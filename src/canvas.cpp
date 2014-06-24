#include <simplecpp>
#include <cstring>
#include <cstdlib>

#ifdef _WIN32

    #include <graphics.h>
    using namespace std;
    // Basic information
    int screen_number=999;
    int screen_width;
    int screen_height;
    int mouse_x,mouse_y; // mouse cordinates
    int ButtonPress,ButtonRelease,MotionNotify,KeyPress;
    char chr;
    int curr_d;
    //Pixmap screenBG;  // BG = background:to keep track of lines drawn by sprites.
                      // lines which are sprites are not drawn on this.
    int screenBG=2;
    //Pixmap screenTmp;
    int screenTmp=1;

    unsigned int size;
    void *image;
    int flag=1;

    struct LtSprite
    {
      bool operator()(const Sprite* s1, const Sprite* s2) const {
        return s1->getZIndex() < s2->getZIndex();
      }
    };

    namespace simplecpp{
      double randuv(double u, double v){
        return u + (v-u)*rand()/(1.0+RAND_MAX);
      }

      void srand(unsigned int seed){
        std::srand(seed);
      }

      void abort(){ std::abort(); }

      int canvas_width(){
        return screen_width;
      }
      int canvas_height(){
        return screen_height;
      }

      std::multiset<Sprite *, LtSprite> s_sprite;

      void wait(float duration){
        //usleep((int) (duration*1000000));
        delay((int) (duration * 1000));
      }


      int initCanvas(const char window_title[], int width, int height){
        screen_number=initwindow(width,height, window_title, 0,0); // creating user screen
        setmousequeuestatus(WM_LBUTTONUP);
        setmousequeuestatus(WM_LBUTTONDOWN);
        setmousequeuestatus(WM_MOUSEMOVE);
        setbkcolor(COLOR(255,255,255));
        cleardevice();
        setcolor(COLOR(0,0,0));
        setlinestyle(SOLID_LINE, 1, 2);
       if(width == -1){
          screen_width = (getwindowwidth( ) -100);
          screen_height = (getwindowheight( ) -100);
        }
        else{
          screen_width = width;
          screen_height= height;
        }

    setactivepage(screen_number);
    size = imagesize(0,0,screen_width, screen_height);
    image = malloc(size);
    getimage(0,0,screen_width, screen_height, image);
    setactivepage(screenBG);
    putimage(0, 0, image, COPY_PUT);
    setcolor(COLOR(0,0,0));
    curr_d=screen_number;
    free(image);
       return 0;
      }

      void closeCanvas(){
        closegraph( );
        s_sprite.clear();    // Delete all elements from set
      }


      void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width){
           setactivepage(curr_d);
        setcolor(line_color);
        setlinestyle(SOLID_LINE, 1, line_width);
        line(start.x, start.y, end.x, end.y);
      }

      void imprintLine(short x1, short y1, short x2, short y2,
    		   Color line_color, unsigned int line_width){
         setactivepage(curr_d);
        setcolor(line_color);
        setlinestyle(SOLID_LINE, 1, line_width);
        line(x1, y1, x2, y2);
        setcolor(COLOR(0,0,0));
      }

      void drawPoint(XPoint point, Color point_color){

        setactivepage(curr_d);
        setcolor(point_color);
        putpixel(point.x, point.y, point_color);
        setcolor(COLOR(0,0,0));
      }

      void drawCircle(XPoint centre, int radius, Color fill_color, bool fill, unsigned int line_width, int line_style){
         setactivepage(curr_d);
        // Check fill
        if(fill){
          line_width = radius;
          radius /= 2;
        }

        setcolor(fill_color);
        setlinestyle(line_style, 1, line_width);
        arc(centre.x-radius, centre.y - radius, 0, 360, radius);
        setcolor(COLOR(0,0,0));
      }


      void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill, unsigned int line_width, int line_style){

        setactivepage(curr_d);
        setfillstyle(SOLID_FILL, fill_color);
        setlinestyle(line_style, 1, line_width);
        setcolor(fill_color);
        if(fill)
          fillellipse(centre.x , centre.y , width/2, height/2);
        else
          ellipse(centre.x , centre.y , 0, 360, width/2, height/2);
        setcolor(COLOR(0,0,0));
      }

      void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill, unsigned int line_width, int line_style){
        setactivepage(curr_d);
        setfillstyle(SOLID_FILL, fill_color);
        setlinestyle(line_style, 1, line_width);
        setcolor(fill_color);
        if(fill)
         {
    	////converting 2d array(XPoint type) to 1d array
    	      int poits[npoints*2];
    	      for(int i=0,j=0;i<npoints;i++)
    	      {
                poits[j++]=points[i].x;
                poits[j++]=points[i].y;
                }
    	        fillpoly(npoints, poits);
        }
        else{

          XPoint pts[npoints + 1];
          int iter;

          // Create array with closed list
          for(iter = 0; iter < npoints; iter ++){
    	pts[iter] = points[iter];
          }

          pts[iter] = points[0];
          //converting 2d array(XPoint type) to 1d array
          int poits[(npoints+1)*2];
    	      for(int i=0,j=0;i<npoints+1;i++)
    	      {
                poits[j++]=pts[i].x;
                poits[j++]=pts[i].y;
                }
    	        drawpoly(npoints+1, poits);
          //XDrawLines(display, curr_d, gc, pts, npoints + 1, CoordModeOrigin);

        }

        //XSync(display, false);
        setcolor(COLOR(0,0,0));
      }

      void addSprite(Sprite *t){
        if(t){
          s_sprite.insert(t);
        }
      }

      void removeSprite(Sprite *t){
        if(t){
          for(std::multiset<Sprite *>::iterator iter = s_sprite.begin();
    	  iter != s_sprite.end(); iter ++){
    	if((*iter) == t){s_sprite.erase(iter); break;}
          }
        }
        repaint();
      }

      void c_imprint(Sprite* s){

        //Drawable temp;
         int temp;
        //temp = curr_d;
        temp = curr_d;
        //curr_d = screenBG;
        curr_d= screenBG;
        s->paint();
        //curr_d = temp;
        curr_d=temp;
      }


      bool globalRepaintFlag = true;
      void beginFrame(){
        globalRepaintFlag = false;
      }
      void endFrame(){
        globalRepaintFlag = true;
        repaint();
      }


      void repaint(){
        if(screen_number==999){ // changed display to screen_number
          cout << "You must first call initCanvas before "<<
    	"using any graphics features.\n";
    	wait(5);
          exit(1);
        }

        if(globalRepaintFlag){
          int tl_x=0,tl_y=0,width=canvas_width(),height=canvas_height();
            setactivepage(screenBG);
            size = imagesize(0, 0,canvas_width(), canvas_height());
            image = malloc(size);
            getimage(tl_x, tl_y,width, height, image);
            setactivepage(screenTmp);
            putimage(tl_x, tl_y, image, COPY_PUT);

            //     curr_d = screenTmp;
            curr_d=screenTmp;
          for(std::multiset<Sprite *>::iterator iter = s_sprite.begin();
    	  iter != s_sprite.end(); iter ++){
    	(*iter)->paint();
          }
        setactivepage(screenTmp);
        getimage(tl_x, tl_y,width, height, image);
        setactivepage(screen_number);
        putimage(tl_x, tl_y, image, COPY_PUT);
        free(image);
        curr_d=screen_number;
        }
      }


      int textWidth(char op){
        string s;
        s= op;
        return  textWidth(s);
      }

      int textWidth(string text){
        //return XTextWidth(xfs,text.c_str(), text.size());
        char txt[text.size() + 1];
        strcpy(txt, text.c_str());
        return textwidth(txt);
      }
      int textHeight(){
        //return xfs->ascent + xfs->descent;
        return 16; // default height 16
      }
      int textDescent(){
        //return xfs->descent;
        return 0;
      }

      void drawText(Position position, string text, Color clr){
        XPoint p;
        p.x =(int) position.getX(); p.y = (int) position.getY();
        drawText(p, text.c_str(), clr);
      }

      void drawText(float x, float y, string text, Color clr){
        XPoint p;
        p.x = (int)x; p.y = (int)y;
        drawText(p, text.c_str(), clr);
      }


      void drawText(XPoint position, string message, Color clr){
        setactivepage(curr_d);
        char *cstr = new char [message.size()+1];
        strcpy (cstr, message.c_str());
          setcolor(clr);
    outtextxy(position.x+1-textWidth(message)/2, position.y -textHeight()/2 - textDescent(), cstr);

        setcolor(COLOR(0,0,0));
      }

  void drawText(XPoint position, const char* text, Color clr){
     setactivepage(curr_d);
     setcolor(clr);
     outtextxy(position.x, position.y, (char*)text);
     setcolor(COLOR(0,0,0));
      }

      void spriteStatus(){
        cout<<"Count: "<<s_sprite.size()<<endl;
        for(std::multiset<Sprite *>::iterator iter = s_sprite.begin(); iter != s_sprite.end(); iter ++){
          cout<<"["<<"]-->"<<(*iter)<<endl;
        }
      }


        bool Button_Down = false;
        void Up_handler(int x, int y)
        {
            Button_Down = false;
        }
        void nextEvent(XEvent &event)
        {
        //XSync(display, False);
        clearmouseclick(WM_LBUTTONDOWN);
        clearmouseclick(WM_LBUTTONUP);

        while(1)
        {
            ButtonPress=0;
            ButtonRelease=0;
            MotionNotify=0;
            KeyPress =0;
            clearmouseclick(WM_MOUSEMOVE);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                ButtonPress=1;
                event.type =ButtonPress;
                getmouseclick(WM_LBUTTONDOWN,event.xbutton.x,event.xbutton.y);
                event.xmotion.x=event.xbutton.x;
                event.xmotion.y=event.xbutton.y;
                Button_Down=true; //true
            }
            if(ismouseclick(WM_LBUTTONUP))
            {

                Button_Down=false; //false
                ButtonRelease=2;
                event.type= ButtonRelease;
                getmouseclick(WM_LBUTTONUP,event.xbutton.x,event.xbutton.y);
                event.xmotion.x=event.xbutton.x;
                event.xmotion.y=event.xbutton.y;
            }
            if(Button_Down && ismouseclick(WM_MOUSEMOVE))
                {
                MotionNotify=3;
                event.type= MotionNotify;
                getmouseclick(WM_MOUSEMOVE,event.xbutton.x,event.xbutton.y);
                event.xbutton.x=mousex();
                event.xbutton.y=mousey();
                registermousehandler(WM_LBUTTONUP, Up_handler);
                }

            if(kbhit())
            {
                chr=getch();
                KeyPress=4;
                event.type=KeyPress;
            }

            if(ButtonPress || ButtonRelease || MotionNotify || KeyPress)
                return;
        }
    }

      char charFromEvent(XEvent &event){
            char c;
            if(kbhit())
            {
                c=getch();
                return c;
            }
        return chr;
      }


      void echoKey(XEvent &event){
        char c = charFromEvent(event);
        string msg(1,c);
        int tw = textwidth(msg.c_str());
        if(flag==1)
        {
            event.xkey.x=0;
            event.xkey.y=0;
            flag=0;
        }
        drawText(event.xkey.x+tw/2, event.xkey.y, string(1,c));
        event.xkey.x +=tw;
      }


      bool checkEvent(XEvent &event){
            ButtonPress=0;
            ButtonRelease=0;
            MotionNotify=0;
            KeyPress=0;
            clearmouseclick(WM_MOUSEMOVE);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                ButtonPress=1;
                event.type =ButtonPress;
                getmouseclick(WM_LBUTTONDOWN,event.xbutton.x,event.xbutton.y);
                event.xmotion.x=event.xbutton.x;
                event.xmotion.y=event.xbutton.y;
                Button_Down=true; //true
            }
            if(ismouseclick(WM_LBUTTONUP))
            {

                Button_Down=false; //false
                ButtonRelease=2;
                event.type= ButtonRelease;
                getmouseclick(WM_LBUTTONUP,event.xbutton.x,event.xbutton.y);
                event.xmotion.x=event.xbutton.x;
                event.xmotion.y=event.xbutton.y;
            }
            if(Button_Down && ismouseclick(WM_MOUSEMOVE))
                {
                MotionNotify=3;
                event.type= MotionNotify;
                getmouseclick(WM_MOUSEMOVE,event.xbutton.x,event.xbutton.y);
                event.xbutton.x=mousex();
                event.xbutton.y=mousey();
                registermousehandler(WM_LBUTTONUP, Up_handler);
                }
            if(kbhit())
            {
                KeyPress=4;
                event.type=KeyPress;
                chr=getch();
            }
       if(ButtonPress || ButtonRelease || MotionNotify || KeyPress)
        return true;
       return false;
      }

      bool mouseDragEvent(XEvent &event){
        return event.type==MotionNotify;
      }

      bool mouseButtonPressEvent(XEvent &event){
        return event.type==ButtonPress;
      }


      bool mouseButtonReleaseEvent(XEvent &event){
        return event.type==ButtonRelease;
      }

      bool keyPressEvent(XEvent &event){

        return event.type == KeyPress;
      }

      int getClick(){

        XEvent event;
        clearmouseclick(WM_LBUTTONDOWN);
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_MOUSEMOVE);
        while(true){
          nextEvent(event);
          if(ButtonPress){
            return event.xbutton.x * 65536 + event.xbutton.y;
          }

        }
        return 0;
      }

    } //end of simplecpp namespace
    Color COLOR(const char *color_string){
    if(screen_number==999){ // changed display to screen_number
          cout << "You must first call initCanvas before "<<
    	"using any graphics features.\n";
    	wait(5);
          exit(1);
        }

          if( strcmp(color_string, "red")==0)
              return ::COLOR(255,0,0);
          else if( strcmp(color_string, "green")==0)
              return ::COLOR(0,255,0);
          else if( strcmp(color_string, "blue")==0)
              return ::COLOR(0,0,255);
          else if( strcmp(color_string, "yellow")==0)
              return ::COLOR(255,255,0);
          else if( strcmp(color_string, "black")==0)
              return ::COLOR(0,0,0);
          else
              return ::COLOR(255,255,255);
      }

#elif __linux__
using namespace std;
Display *display = NULL; // A connection to X server

// Basic information
int screen_number;
int screen_width;
int screen_height;

Window canvas_window;

unsigned long white_pixel;
unsigned long black_pixel;

Colormap cmap;

GC gc;
XGCValues gc_vals;

XFontStruct *xfs;

// Current drawable
Drawable curr_d;

Pixmap screenBG;  // BG = background:to keep track of lines drawn by sprites.
                  // lines which are sprites are not drawn on this.

Pixmap screenTmp;

struct LtSprite
{
  bool operator()(const Sprite* s1, const Sprite* s2) const {
    return s1->getZIndex() < s2->getZIndex();
    //    return s1 < s2;
  }
};

namespace simplecpp{
  double randuv(double u, double v){
    return u + (v-u)*rand()/(1.0+RAND_MAX);
  }

  void srand(unsigned int seed){
    std::srand(seed);
  }

  void abort(){ std::abort(); }

  int canvas_width(){
    return screen_width;
  }
  int canvas_height(){
    return screen_height;
  }

  std::multiset<Sprite *, LtSprite> s_sprite;

  void wait(float duration){
    usleep((int) (duration*1000000));
  }


  int initCanvas(const char window_title[], int width, int height){

    display = XOpenDisplay(NULL);    // Connect X server by opening a display

    if(!display){
      cerr<<"Unable to connect X server\n";
      return 1;
    }

    screen_number = DefaultScreen(display);

    if(width == -1){
      screen_width = (DisplayWidth(display, screen_number) -100);
      screen_height = (DisplayHeight(display, screen_number) -100);
    }
    else{
      screen_width = width;
      screen_height= height;
    }

    white_pixel = WhitePixel(display, screen_number);
    black_pixel = BlackPixel(display, screen_number);

    //   cout << "x1,y1 " << x1<<","<<y1<<" x2,y2: "<<x2<<","<<y2<<
    //     " screen_width,height "<< screen_width << ","<<screen_height<<endl;
    canvas_window = XCreateSimpleWindow(display,
					RootWindow(display, screen_number),
					0,0, // left top corner.  doesnt work.
					screen_width, screen_height,
					1,
					black_pixel,
					white_pixel);

    XSetStandardProperties(display, canvas_window, window_title,
			   window_title, None, NULL, 0, NULL);

    XSelectInput(display, canvas_window,
		 ExposureMask|ButtonPressMask|ButtonReleaseMask|KeyPressMask|ButtonMotionMask);
    //	       ExposureMask|ButtonPressMask|KeyPressMask|PointerMotionMask);

    XMapWindow(display, canvas_window);    // Map canvas window to display
    XSync(display, True);  // flush all output requests and discards events


    gc_vals.function = GXcopy;
    //  gc_vals.foreground = Color(COLOR("black"));
    gc_vals.line_width = 2;
    gc_vals.line_style = LineSolid;
    gc_vals.cap_style = CapButt;
    gc_vals.join_style = JoinMiter;

    gc = XCreateGC(display, canvas_window, 0 ,0);    // Create GC

    if(gc < 0){
      cerr<<"Unable to create graphic context.\n";
      return 2;                            // ERROR CODE 2: gc error
    }


    xfs = XLoadQueryFont(display, "-*-helvetica-bold-r-normal-*-24-*");
    if (!xfs) {
      xfs = XLoadQueryFont(display, "fixed");
    }
    if(!xfs){
      cout << "Cannot load font.  You will not be able to use Text.\n";
    }

    //XClearWindow(display, canvas_window);
    //XMapRaised(display, canvas_window);

    cmap = DefaultColormap(display, screen_number);

    // Flush all events to X server and wait
    XSync(display, False);

    screenBG =XCreatePixmap(display, canvas_window,
			    screen_width, screen_height,
			    XDefaultDepth(display, screen_number));
    //    XCopyArea(display, canvas_window, screenBG, gc, 0,0,screen_width, screen_height, 0,0);

    //  {int p; cin >> p;}
    wait(0.1);
    XSync(display, False);

    screenTmp=XCreatePixmap(display, canvas_window, screen_width, screen_height,
			    XDefaultDepth(display, screen_number));

    curr_d = canvas_window;

    Rectangle r(canvas_width()/2.0, canvas_height()/2.0,
		canvas_width(), canvas_height());
    r.setColor(COLOR("white"));
    r.setFill();
    r.imprint();


    return 0;
  }

  void closeCanvas(){
    XSync(display, True);    // Flush all events to X server and wait

    XFreePixmap(display, screenBG);
    XFreePixmap(display, screenTmp);

    XFreeGC(display, gc);    // Delete GC

    XDestroyWindow(display, canvas_window);

    XCloseDisplay(display);

    display = NULL;
    s_sprite.clear();    // Delete all elements from set
  }


  void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width){

    gc_vals.foreground = line_color;
    gc_vals.line_width = line_width;

    XChangeGC(display, gc, GCForeground | GCLineWidth, &gc_vals);

    //XSync(display, false);

    // Draw line
    XDrawLine(display, curr_d, gc, start.x, start.y, end.x, end.y);

    //  XSync(display, false);

  }

  void imprintLine(short x1, short y1, short x2, short y2,
		   Color line_color, unsigned int line_width){

    gc_vals.foreground = line_color;
    gc_vals.line_width = line_width;

    XChangeGC(display, gc, GCForeground | GCLineWidth, &gc_vals);

    XDrawLine(display, curr_d, gc, x1, y1, x2, y2);

  }


  Color COLOR(const char *color_string){
    if(!display){
      cout << "You must first call initCanvas before "<<
	"using any graphics features.\n";
      exit(1);
    }
    XColor screen_color, true_color;
    XAllocNamedColor(display, cmap, color_string, &screen_color, &true_color );

    return screen_color.pixel;
  }

  Color COLOR(unsigned short red, unsigned short green, unsigned short blue){
    Color clr = 0;

    clr = red;
    clr = clr << 8;
    clr = clr | green;
    clr = clr << 8;
    clr = clr | blue;

    return clr;
  }

  void drawPoint(XPoint point, Color point_color, int function){

    gc_vals.foreground = point_color;

    XChangeGC(display, gc, GCForeground, &gc_vals);

    XSync(display, false);

    XDrawPoint(display, curr_d, gc, point.x, point.y);

    XSync(display, false);

  }

  void drawCircle(XPoint centre, int radius, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int function){
    GC local_gc;
    XGCValues local_gc_vals;

    // Check fill
    if(fill){
      line_width = radius;
      radius /= 2;
    }

    // Fill the structure
    local_gc_vals.function = function;
    local_gc_vals.foreground = fill_color;
    local_gc_vals.line_width = line_width;
    local_gc_vals.line_style = line_style;
    local_gc_vals.cap_style = cap_style;
    local_gc_vals.join_style = join_style;

    // Create gc for current drawable
    local_gc = XCreateGC(display, curr_d, GCFunction | GCForeground | GCLineWidth | GCLineStyle | GCCapStyle | GCJoinStyle, &local_gc_vals);

    XSync(display, false);

    // Draw full arc
    XDrawArc(display, curr_d, local_gc, centre.x - radius, centre.y - radius, radius * 2, radius * 2, 0, 23040);

    XSync(display, false);

    // Free temporary GC
    XFreeGC(display, local_gc);
  }


  void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int function){

    gc_vals.foreground = fill_color;
    gc_vals.line_width = line_width;

    XChangeGC(display, gc, GCForeground | GCLineWidth, &gc_vals);

    //  XSync(display, false);

    if(fill)
      XFillArc(display, curr_d, gc, centre.x - width / 2, centre.y - height / 2, width, height, 0, 23040);
    else
      XDrawArc(display, curr_d, gc, centre.x - width / 2, centre.y - height / 2, width, height, 0, 23040);

    //  XSync(display, false);

  }

  void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int fill_rule, int function){

    gc_vals.foreground = fill_color;
    gc_vals.line_width = line_width;
    gc_vals.fill_rule = fill_rule;
    XChangeGC(display, gc, GCForeground | GCLineWidth | GCFillRule, &gc_vals);

    //  XSync(display, false);


    if(fill)
      XFillPolygon(display, curr_d, gc, points, npoints,
		   Complex, CoordModeOrigin);
    else{

      XPoint pts[npoints + 1];
      int iter;

      // Create array with closed list
      for(iter = 0; iter < npoints; iter ++){
	pts[iter] = points[iter];
      }

      pts[iter] = points[0];

      XDrawLines(display, curr_d, gc, pts, npoints + 1, CoordModeOrigin);
    }

    //XSync(display, false);

  }

  void addSprite(Sprite *t){
    if(t){
      s_sprite.insert(t);
    }
  }

  void removeSprite(Sprite *t){
    if(t){
      for(std::multiset<Sprite *>::iterator iter = s_sprite.begin();
	  iter != s_sprite.end(); iter ++){
	if((*iter) == t){s_sprite.erase(iter); break;}
      }
    }
    repaint();
  }

  void c_imprint(Sprite* s){
    Drawable temp;
    temp = curr_d;
    curr_d = screenBG;
    s->paint();
    curr_d = temp;
  }


  bool globalRepaintFlag = true;
  void beginFrame(){
    globalRepaintFlag = false;
  }
  void endFrame(){
    globalRepaintFlag = true;
    repaint();
  }

  void repaint(){
    if(!display){
      cout << "Repaint: You must first call initCanvas before "<<
	"using any graphics features.\n";
      exit(1);
    }

    if(globalRepaintFlag){
      int tl_x=0,tl_y=0,width=canvas_width(),height=canvas_height();
      XCopyArea(display, screenBG, screenTmp, gc,
		tl_x, tl_y, width, height, tl_x, tl_y);

      curr_d = screenTmp;

      for(std::multiset<Sprite *>::iterator iter = s_sprite.begin();
	  iter != s_sprite.end(); iter ++){
	(*iter)->paint();
      }

      XCopyArea(display, screenTmp, canvas_window, gc,
		tl_x, tl_y, width, height, tl_x, tl_y);

      XSync(display, false);
      curr_d = canvas_window;
    }
  }


  void nextEvent(XEvent &event){
    XSync(display, False);
    XNextEvent(display, &event);
  }

  char charFromEvent(XEvent &event){
    //char c = XKeycodeToKeysym(display, event.xkey.keycode, event.xkey.state);

    int keysyms_per_keycode_return;
    char c = *XGetKeyboardMapping(display,event.xkey.keycode,
				    1,&keysyms_per_keycode_return);
    return c;
  }


  void echoKey(XEvent &event){
    char c = charFromEvent(event);
    int tw = XTextWidth(xfs,&c,1);
    drawText(event.xkey.x+tw/2, event.xkey.y, string(1,c));
    XWarpPointer(display, None, None, 0, 0, 0,0, tw, 0);
  }


  int textWidth(char op){
    string s;
    s= op;
    return  textWidth(s);
  }

  int textWidth(string text){
    return XTextWidth(xfs,text.c_str(), text.size());
  }
  int textHeight(){
    return xfs->ascent + xfs->descent;
  }
  int textDescent(){
    return xfs->descent;
  }

  void drawText(Position position, string text, Color clr){
    XPoint p;
    p.x = position.getX(); p.y = position.getY();
    drawText(p, text.c_str(), clr);
  }

  void drawText(float x, float y, string text, Color clr){
    XPoint p;
    p.x = x; p.y = y;
    drawText(p, text.c_str(), clr);
  }


  void drawText(XPoint position, string message, Color clr){
    GC local_gc;
    XGCValues local_gc_vals;

    // Fill the structure
    local_gc_vals.foreground = clr;
    local_gc_vals.font = xfs->fid;

    // Create gc for current drawable
    local_gc = XCreateGC(display, curr_d, GCForeground
			 |GCFont, &local_gc_vals);

    char *cstr = new char [message.size()+1];
    strcpy (cstr, message.c_str());

    XTextItem ti;
    ti.chars = cstr;
    ti.nchars = strlen(cstr);
    ti.delta = 0;
    ti.font = None;

    XSync(display, false);

    XDrawText(display, curr_d, local_gc,
	      position.x-textWidth(message)/2,
	      position.y+textHeight()/2 - textDescent(), &ti, 1);

    XSync(display, false);

    // Free temporary GC
    XFreeGC(display, local_gc);
  }

  void drawText(XPoint position, const char* text, Color clr){
    GC local_gc;
    XGCValues local_gc_vals;

    // Fill the structure
    local_gc_vals.foreground = clr;
    local_gc_vals.font = xfs->fid;

    // Create gc for current drawable
    local_gc = XCreateGC(display, curr_d, GCForeground
			 |GCFont
			 , &local_gc_vals);


    XTextItem ti;

    ti.chars = (char*)text;
    ti.nchars = strlen(text);
    ti.delta = 0;
    ti.font = None;

    XSync(display, false);

    XDrawText(display, curr_d, local_gc,
	      position.x-XTextWidth(xfs,text,strlen(text))/2,
	      position.y+textHeight()/2 - textDescent(), &ti, 1);

    XSync(display, false);

    // Free temporary GC
    XFreeGC(display, local_gc);
  }

  void spriteStatus(){
    cout<<"Count: "<<s_sprite.size()<<endl;
    for(std::multiset<Sprite *>::iterator iter = s_sprite.begin(); iter != s_sprite.end(); iter ++){
      cout<<"["<<"]-->"<<(*iter)<<endl;
    }
  }

  bool checkEvent(XEvent &event){
    if(XCheckMaskEvent(display, ButtonReleaseMask|ButtonPressMask|KeyPressMask, &event))
      return true;
    return false;
  }

  bool mouseDragEvent(XEvent &event){
    return event.type == MotionNotify;
  }

  bool mouseButtonPressEvent(XEvent &event){
    return event.type == ButtonPress;
  }

  bool mouseButtonReleaseEvent(XEvent &event){
    return event.type == ButtonRelease;
  }

  bool keyPressEvent(XEvent &event){
    return event.type == KeyPress;
  }

  int getClick(){
    XEvent event;

    XSync(display, true); // discard all previous clicks
    while(true){
      nextEvent(event);
      if(event.type == ButtonPress){
	return event.xbutton.x * 65536 + event.xbutton.y;
      }
    }
  }

}
#endif

