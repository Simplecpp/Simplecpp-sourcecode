#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

//#include <simplecpp>
 #ifdef _WIN32
    #include <graphics.h>
 #endif
namespace simplecpp{
  double randuv(double u, double v);
  void srand(unsigned int);
  void wait(float duration);
  void abort();

  int initCanvas(const char window_title[]="Simplecpp Canvas",
		 int w=500, int h=500);
  // creates the graphics window

  void closeCanvas();

  int canvas_width();  // return the width of the canvas
  int canvas_height();
  int textWidth(string text);
  int textWidth(char op);
  int textHeight();
  int textDescent();

  void addSprite(Sprite *t);  // adds *t into the list of active sprites
                              // does not repaint immediately?
  void removeSprite(Sprite *t);

  
  // paints the line into the the background

  /* draw... : draw ... onto the current buffer. */

  void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width=0);

    #ifdef _WIN32
        void drawPoint(XPoint point, Color point_color);// removed GXcopy
        void drawCircle(XPoint centre, int radius, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=SOLID_LINE); // removed , int cap_style=CapButt, int join_style=JoinMiter, int function=GXcopy
        void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=SOLID_LINE); // removed , int cap_style=CapButt, int join_style=JoinMiter, int function=GXcopy
        void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=SOLID_LINE); //removed , int cap_style=CapButt, int join_style=JoinMiter, int fill_rule=WindingRule, int function=GXcopy
        void drawText(Position position, string text, Color clr = COLOR(0,0,255)); // removed Color("Blue")
        void drawText(float x, float y, string text, Color clr = COLOR(0,0,255));// removed Color("Blue")
    #elif __linux__
        void drawPoint(XPoint point, Color point_color, int function=GXcopy);
        void drawCircle(XPoint centre, int radius, Color fill_color, bool fill=true, unsigned int line_width=0, int line_style=LineSolid, int cap_style=CapButt, int join_style=JoinMiter, int function=GXcopy);
        void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill=true, unsigned int line_width=1, int line_style=LineSolid, int cap_style=CapButt, int join_style=JoinMiter, int function=GXcopy);
        void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill=true, unsigned int line_width=0, int line_style=LineSolid, int cap_style=CapButt, int join_style=JoinMiter, int fill_rule=WindingRule, int function=GXcopy);
        void drawText(Position position, string text, Color clr = Color("Blue"));
        void drawText(float x, float y, string text, Color clr = Color("Blue"));
        Color COLOR(const char *color_string);  // creates a colour.
        Color COLOR(unsigned short red, unsigned short green, unsigned short blue);
    #endif
  void imprintLine(short x1, short y1, short x2, short y2,  Color line_color=COLOR(0,0,0), unsigned int line_width=2);
  void drawText(XPoint position, const char *text, Color clr);

  void drawText(XPoint position, string message, Color clr);

  void c_imprint(Sprite* s);  // paints *s into the background
  void repaint();  // paint the current screen into new buffer, then transfer.
  void beginFrame();  // suspend painting.  set flag appropriately.
  void endFrame();    // resume painting.  reset flag.

  void nextEvent(XEvent &event);  // wait for an event: mouseclick, keypress.
  bool mouseDragEvent(XEvent &event);  // true if event is drag
  bool keyPressEvent(XEvent &event);
  bool mouseButtonPressEvent(XEvent &event);
  bool mouseButtonReleaseEvent(XEvent &event);
  char charFromEvent(XEvent &event);  // return char whose key was pressed.
  bool checkEvent(XEvent &event);
  // true if some event happened since last nextEvent.

  void echoKey(XEvent &event);  // print value on screen
  void spriteStatus();
  int getClick();  // wait for a click, and return xclickpos*65536+yclickpos.
}
#ifdef _WIN32
    Color COLOR(const char *color_string);  // creates a colour.
#endif

#endif
