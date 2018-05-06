
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <gl/glaux.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <stack>
#include <list>
using namespace std;
const double PI = acos(-1.0);

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

extern double Move_x, Move_y, Move_z;

class Point {
public:
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	Point operator + (Point a) const{
		return Point(x + a.x, y + a.y);
	}
};

class TPoint {
public:
	double x, y, z;
	TPoint(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
	TPoint operator + (TPoint Q) const {
		return TPoint(x + Q.x, y + Q.y, z + Q.z);
	}
	TPoint operator * (TPoint Q) const {
		return TPoint(x * cos(Q.x), x * sin(Q.x), 0);
	}
};

class Color {
public:
	double x, y, z; 
	Color(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

class OneOne { // 1
public:
	bool init;     // the mark variable of Init function
	bool reshape;  // the mark variable of Reshape function
	bool Mouse;    // the mark variable of Mouse function 
	bool Keyboard; // the mark variable of Keyboard function
	bool Motion;   // the mark variable of Mouse move fuction
	OneOne(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0, 0, 0, 1);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	};   // 改变窗口大小时对视窗进行的操作
	void Display(void) { // 绘制代码
		//glClearColor(0.0, 0.0, 0.0, 0.0);
		//glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0f, 1.0f, 1.0f);
		glRectf(-0.5f + Move_x, -0.5f + Move_y, 0.5f + Move_x, 0.5f + Move_y);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f + Move_x, 1.0f + Move_y);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.8f + Move_x, -0.5f + Move_y);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.8f + Move_x, -0.5f + Move_y);
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.4f + Move_x, -0.4f + Move_y);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.0f + Move_x, 0.0f + Move_y);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.4f + Move_x, 0.4f + Move_y);
		glEnd();
		glFlush();
	}
};

class OneTwo { // 2
public:
	bool init;     // the mark variable of Init function
	bool reshape;  // the mark variable of Reshape function
	bool Mouse;    // the mark variable of Mouse function 
	bool Keyboard; // the mark variable of Keyboard function
	bool Motion;   // the mark variable of Mouse move fuction
	OneTwo(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0, 0, 0, 1);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	};   // 改变窗口大小时对视窗进行的操作
	void Triangle(Color c1, Color c2, Color c3, Point a, Point b, Point c) {
		glBegin(GL_TRIANGLES);
		glColor3d(c1.x, c1.y, c1.z); glVertex2d(a.x + Move_x, a.y + Move_y);
		glColor3d(c2.x, c2.y, c2.z); glVertex2d(b.x + Move_x, b.y + Move_y);
		glColor3d(c3.x, c3.y, c3.z); glVertex2d(c.x + Move_x, c.y + Move_y);
		glEnd();
	}
	void Display(void) { // 绘制代码
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0f, 1.0f, 1.0f);
		glRectf(-0.8f + Move_x, -0.8f + Move_y, 0.8f + Move_x, 0.8f + Move_y);

		Triangle(Color(0, 1, 0), Color(1, 1, 0), Color(1, 0, 0), Point(-0.8, 0.8), Point(0.8, 0.8), Point(0, -0.8));
		

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 1.0f);
		GLfloat r = 0.5;
		for (int i = 1; i <= 1000; i++) {
			glVertex2f(r * cos(PI / 500 * i) + Move_x, r * sin(PI / 500 * i) + Move_y);
		}
		glEnd();

		GLfloat a = 1 / (2 - 2 * cos(72 * PI / 180)); // ???
		GLfloat x = a * cos(18 * PI / 180);
		GLfloat y = a * sin(18 * PI / 180);
		GLfloat z = a * cos(18 * PI / 180);
		glColor3f(0.0f, 0.0f, 1.0f); glPointSize(3);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0f + Move_x, a + Move_y); glVertex2f(0.5f + Move_x, -z + Move_y);
		glVertex2f(-x + Move_x, y + Move_y);   glVertex2f(x + Move_x, y + Move_y);
		glVertex2f(-0.5f + Move_x, -z + Move_y);
		glEnd();

		Triangle(Color(1, 0, 0), Color(0, 0, 1), Color(1, 0, 1), Point(-0.65, -0.6), Point(-0.6, -0.7), Point(-0.7, -0.7));
		
		Triangle(Color(1, 0, 0), Color(1, 0, 1), Color(1, 1, 0), Point(0.65, -0.6), Point(0.7, -0.7), Point(0.6, -0.7));
		
		glFlush();
	}
};

class OneThreeOne { // 3
public:
	bool init;     // the mark variable of Init function
	bool reshape;  // the mark variable of Reshape function
	bool Mouse;    // the mark variable of Mouse function 
	bool Keyboard; // the mark variable of Keyboard function
	bool Motion;   // the mark variable of Mouse move fuction
	OneThreeOne(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0, 0, 0, 1);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	};   // 改变窗口大小时对视窗进行的操作
 	void polygon(Color *c, Point *p, int n) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++) {
			glColor3f(c[i].x, c[i].y, c[i].z); glVertex2f(p[i].x + Move_x, p[i].y + Move_y);
		}
		glEnd();
	}
	void Display(void) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		glRectf(-0.5f + Move_x, -0.5f + Move_y, 0.5f + Move_x, 0.5f + Move_y);
		Color c[10]; Point p[10];
		for (int i = 0; i < 4; i++) c[i] = { 1, 0, 0 };
		p[0] = { 0, 0.5 }; p[1] = { 0.5, 0 }; p[2] = { 0, -0.5 }; p[3] = { -0.5, 0 };
		polygon(c, p, 4);
		for (int i = 0; i < 3; i++) c[i] = { 0, 0, 1 };
		p[0] = { 0, 1 }; p[1] = { 0.5, 0.5 }; p[2] = { -0.5, 0.5 };
		polygon(c, p, 3);
		for (int i = 0; i < 3; i++) c[i] = { 1, 1, 0 };
		p[0] = { 1, 0 }; p[1] = { 0.5, 0.5 }; p[2] = { 0.5, -0.5 };
		polygon(c, p, 3);
		for (int i = 0; i < 3; i++) c[i] = { 1, 0, 1 };
		p[0] = { -1, 0 }; p[1] = { -0.5, -0.5 }; p[2] = { -0.5, 0.5 };
		polygon(c, p, 3);
		for (int i = 0; i < 3; i++) c[i] = { 0, 1, 0 };
		p[0] = { 0, -1 }; p[1] = { 0.5, -0.5 }; p[2] = { -0.5, -0.5 };
		polygon(c, p, 3);
		glFlush();
	}
};

class OneThreeTwo { // 4
public:
	bool init;     // the mark variable of Init function
	bool reshape;  // the mark variable of Reshape function
	bool Mouse;    // the mark variable of Mouse function 
	bool Keyboard; // the mark variable of Keyboard function
	bool Motion;   // the mark variable of Mouse move fuction
	OneThreeTwo(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0, 0, 0, 1);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	};   // 改变窗口大小时对视窗进行的操作
	void polygon(Color *c, Point *p, int n) {
		//glTranslatef(Move_x, Move_y, 0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++) {
			glColor3f(c[i].x, c[i].y, c[i].z);
			glVertex2f(p[i].x + Move_x, p[i].y + Move_y);
		}
		glEnd();
	}
	Color c[10]; Point p[10];
	void Solve(int x, int y, int num) {
		double d = 360 / num / (x + y);
		double D = 0.5 * tan(d * x / 2 * PI / 180);
		for (int i = 0; i < 4; i++) c[i] = { 1, 0, 0 };
		p[0] = { 0, 1 }; p[1] = { D, 0.5 };
		p[2] = { 0, 0 }; p[3] = { -D, 0.5 };
		polygon(c, p, 4);
		for (int i = 1; i <= 3; i++) {
			for (int j = 0; j < 4; j++) {
				swap(p[j].x, p[j].y);
				if (i % 2 == 0) p[j].y *= -1;
			}
			polygon(c, p, 4);
		}
		for (int i = 0; i < 4; i++) c[i] = { 0, 1, 0 };
		p[0] = { sqrt(2.0) / 2, sqrt(2.0) / 2 }; p[1] = { 0.5, D };
		p[2] = { 0, 0 }; p[3] = { D, 0.5 };
		polygon(c, p, 4);
		for (int i = 1; i <= 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (i & 1) p[j].y *= -1;
				else p[j].x *= -1;
			}
			polygon(c, p, 4);
		}
	}
	void Display(void) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		Solve(3, 2, 4);
		glFlush();
	}
};

class TwoOne{ // 5
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard ;  // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	TwoOne(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0, 0, 0, 0);
	}
	void Reshape(int w, int h) {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, (GLdouble)w, 0, (GLdouble)h);
	}
	void LineDDA(int x0, int y0, int x1, int y1) {
		int x, dy, dx, y;
		double m;
		dx = x1 - x0;
		dy = y1 - y0;
		m = dy / dx;
		y = y0;
		glColor3f(1, 1, 0);
		glPointSize(1);
		for (x = x0; x <= x1; x++) {
			glBegin(GL_POINTS);
			glVertex2i(x + Move_x, (int)(y + 0.5) + Move_y);
			glEnd();
			y += m;
		}
	}
	void Display(void) {

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		glRectf(25 + Move_x, 25 + Move_y, 75 + Move_x, 75 + Move_y);

		glPointSize(1);
		glBegin(GL_POINTS);
		glColor3f(1, 1, 0); glVertex2f(100 + Move_x, 200 + Move_y);
		glEnd();

		LineDDA(0, 0, 200, 300);

		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0, 1, 0); glVertex2f(100 + Move_x, 0 + Move_y);
		glColor3f(0, 1, 0); glVertex2f(180 + Move_x, 240 + Move_y);
		glEnd();

		glFlush();
	}
};

class TwoTwo{ // 6
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	TwoTwo(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0, 0, 0, 0);
	}
	void Reshape(int w, int h) {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, (GLdouble)w, 0, (GLdouble)h);
	}
	//int C = 6;
	int R = 1, G = 0, B = 0;
	int W = 2;
	void LineDDA(int x0, int y0, int x1, int y1) {
		int x, dy, dx, y;
		double m;
		dx = x1 - x0;
		dy = y1 - y0;
		m = dy / dx;
		y = y0;
		glColor3f(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		glPointSize(W);
		for (x = x0; x <= x1; x++) {
			glBegin(GL_POINTS);
			glVertex2i(x + Move_x, (int)(y + 0.5) + Move_y);
			glEnd();
			y += m;
		}
	}
	void Display(void) {

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		glRectf(25 + Move_x, 25 + Move_y, 75 + Move_x, 75 + Move_y);

		glPointSize(W);
		glBegin(GL_POINTS);
		glColor3f(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255); glVertex2f(100 + Move_x, 200 + Move_y);
		glEnd();

		LineDDA(0, 0, 200, 300);

		glLineWidth(W);
		glBegin(GL_LINES);
		glColor3f(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255); glVertex2f(100 + Move_x, 0 + Move_y);
		glColor3f(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255); glVertex2f(180 + Move_x, 240 + Move_y);
		glEnd();

		glFlush();
	}
};

extern int op, n;
class TwoThree { // 7
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	TwoThree(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	};   // 改变窗口大小时对视窗进行的操作
	Color c[1000 + 1];
	Point p[1000 + 1], p1[1000 + 1], p2[1000 + 1];
	void Ring(double r, Color C) {
		glColor3d(C.x, C.y, C.z); glBegin(GL_POLYGON);
		for (int i = 0; i < 10000; i++) {
			double D = 360.0 / 10000 * i / 180 * PI;
			glVertex2d(r * cos(D) + Move_x, r * sin(D) + Move_y);
		}
		glEnd();
	}
	void Star(double r, int n, Color C, double r0, Color C1, Color C2) {
		double dis_to_next = 360.0 / n; //顶点间角度
		for (int i = 0; i < n; i++) {
			double D = (dis_to_next * i + 90) / 180 * PI;
			p1[i] = { r * cos(D), r * sin(D) };
		}
		double r_incycle;//次顶点到中心距离
		if (r0 == 0) {
			r_incycle = r * 3 / 8;
		}
		else {
			r_incycle = r0;
		}
		for (int i = 0; i < n; i++) {
			double D = (180 / n + 90 + i * dis_to_next) / 180 * PI;
			p2[i] = { r_incycle * cos(D), r_incycle * sin(D) };
		}
		glColor3d(C.x, C.y, C.z);
		glBegin(GL_POLYGON);//先以次顶点画多边形
		for (int i = 0; i < n; i++) {
			glVertex2d(p2[i].x + Move_x, p2[i].y + Move_y);
		}
		glEnd();
		glColor3d(C.x, C.y, C.z);
		for (int i = 0; i < n; i++) {//再逐步涂色
			glBegin(GL_TRIANGLES);
			glVertex2d(p2[i].x + Move_x, p2[i].y + Move_y);
			glVertex2d(p1[(i + 1) % n].x + Move_x, p1[(i + 1) % n].y + Move_y);
			glVertex2d(p2[(i + 1) % n].x + Move_x, p2[(i + 1) % n].y + Move_y);
			glEnd();
		}
		glColor3f(0, 0, 0);  
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < n; i++) {//把n角星的边变成黑色
			glVertex2d(p1[i].x + Move_x, p1[i].y + Move_y);
			glVertex2d(p2[i].x + Move_x, p2[i].y + Move_y);
		}
		glEnd();
		for (int i = 0; i < n; i++) {
			if (C1.x != -1) {//顶点到中心连线
				glColor3d(C1.x, C1.y, C1.z);
				glLineWidth(1);
				glBegin(GL_LINES);
				glVertex2d(p1[i].x + Move_x, p1[i].y + Move_y);
				glVertex2d(0 + Move_x, 0 + Move_y);
				glEnd();
			}
			if (C2.x != -1) {//次顶点到中心连线
				glColor3d(C2.x, C2.y, C2.z);
				glLineWidth(1);
				glBegin(GL_LINES);
				glVertex2d(p2[i].x + Move_x, p2[i].y + Move_y);
				glVertex2d(0 + Move_x, 0 + Move_y);
				glEnd();
			}
		}
	}
	void myDisplay1(void) {
		glClear(GL_COLOR_BUFFER_BIT);
		Ring(0.5, Color(0, 0, 1 ));
		Star(0.5, 14, Color(1, 1, 1 ), 0.3, Color(-1, 0, 0 ), Color( -1, 0, 0 ));
		Ring(0.265, Color(0, 0, 1 ));
		Ring(0.238, Color(1, 1, 1 ));
		glFlush();
	}
	void myDisplay2(void) {
		glClear(GL_COLOR_BUFFER_BIT);
		Ring(0.55, Color(1, 1, 0));
		Ring(0.5, Color(1, 0, 0));
		Star(0.5, 5, Color(1, 1, 0), 0.18, Color(0, 0, 0), Color(0, 0, 0));
		glFlush();
	}
	void myDisplay3(void) {
		glClear(GL_COLOR_BUFFER_BIT);
		Ring(0.5, Color(1, 0, 1));
		Star(0.5, n, Color(1, 1, 1), 0, Color(1, 0, 0), Color(0, 0, 0));
		glFlush();
	}
	void Display() {
		if (op == 1) {
			myDisplay1();
		}
		else if (op == 2) {
			myDisplay2();
		}
		else {
			myDisplay3();
		}
	}
};

class ThreeOneOne { // 8
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	ThreeOneOne(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0, 0.0, 0.0, 0.0);
	}
	void Reshape(int width, int height) {
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-7.0, 7.0, -5.0, 5.0);
	}
	void DrawSquare() { //绘制中心在原点，边长为2的正方形
		glBegin(GL_POLYGON); //顶点指定需要按逆时针方向
		glVertex2f(-1.0f, -1.0f); //左下点
		glVertex2f(1.0f, -1.0f);  //右下点
		glVertex2f(1.0f, 1.0f);   //右上点
		glVertex2f(-1.0f, 1.0f);  //左上点
		glEnd();
	}
	void Display(void) {
		glClear(GL_COLOR_BUFFER_BIT); //清空

		glPushMatrix();
		glTranslatef(0.0f, 2.0f, 0.0f);
		glScalef(3.0, 0.5, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		DrawSquare(); //上面红色矩形
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-3.0, 0.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		glColor3f(0.0, 1.0, 0.0);
		DrawSquare(); //中间左菱形
		glPopMatrix();


		glTranslatef(3.0, 0.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		glColor3f(0.0, 0.7, 0.0);
		DrawSquare(); //中间中菱形
		glPopMatrix();
		
		glTranslatef(3.0, 0.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		glColor3f(0.0, 0.4, 0.0);
		DrawSquare(); //中间右菱形
		glPopMatrix();

		glPopMatrix();
		glTranslatef(0.0, -3.0, 0.0);
		glScalef(4.0, 1.5, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		DrawSquare(); //下面蓝色矩形

		glFlush();
	}
};

class ThreeOneTwo { // 9
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	double rtri = 1;
	ThreeOneTwo(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//glShadeModel(GL_SMOOTH);//设为smooth处理方式，注意看区别
		glEnable(GL_DEPTH_TEST);//激活深度测试
	}
	void Reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void Display(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
		glLoadIdentity();
		glTranslatef(-1.5f, 0.0f, -6.0f);//请尝试修改此函数，掌握其用法与参数含义
		glRotatef(rtri, 0.0f, 1.0f, 0.0f);//请尝试修改此函数，掌握其用法与参数含义
		glTranslatef(Move_x, Move_y, Move_z); 
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();

		glDisable(GL_DEPTH_TEST);//激活深度测试
		glFlush();
	}
};

class ThreeTwo { // 10
public:
	double rtri = 1; 
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	bool Left = false, Right = false;
	ThreeTwo(bool a = true, bool b = true, bool c = false, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//glShadeModel(GL_SMOOTH);//设为smooth处理方式，注意看区别
		glEnable(GL_DEPTH_TEST);//激活深度测试
	}
	void Reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void Display(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
		glLoadIdentity();
		glTranslatef(-1.5f, 0.0f, -6.0f);//请尝试修改此函数，掌握其用法与参数含义
		glRotatef(rtri, 0.0f, 1.0f, 0.0f);//请尝试修改此函数，掌握其用法与参数含义
		glTranslatef(Move_x, Move_y, Move_z);
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();
		
		glDisable(GL_DEPTH_TEST); //关闭深度测试
		glFlush();
	}
};

class ThreeThreeOne { // 11
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	bool Left = false, Right = false;
	ThreeThreeOne(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	TPoint D_sun_to_earth = { 35, 0, 0 }, D_moon_to_earth = { 15, 0, 0 };
	// 太阳到地球距离35 月亮到地球距离15
	TPoint sun = { 0, 0, 0 }, earth = { 35, 0, 0 }, moon = { 50, 0, 0 };

	// 太阳、地球、月亮的球心坐标
	double Angle_earth_to_sun = 0; // 地球绕太阳的公转角度
	double Angle_moon_to_earth = 0; // 月亮绕地球的公转角度
	double Angle = 10; // 自转角度
	double R_sun = 10, R_earth = 6, R_moon = 3; // 太阳、地球、月亮半径
	void Init() {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		//glShadeModel(GL_FLAT);
		glEnable(GL_DEPTH_TEST);
	}
	void Reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
	}
	void DrawPlanet(double r, TPoint Q, int a, int b) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glRotated(120, 1, 0, 0);
		glTranslatef(Q.x, Q.y, Q.z);
		glTranslatef(Move_x, Move_y, Move_z);
		glRotated(Angle, 0, 0, 1);
		glutWireSphere(r, a, b);
		glPopMatrix();
	}
	void Display(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3d(1, 0, 0);
		DrawPlanet(R_sun, sun, 20, 20); // sun
		glColor3d(0, 0, 1); // earth
		DrawPlanet(R_earth, earth, 20, 20);
		glColor3d(0, 1, 0); // moon
		DrawPlanet(R_moon, moon, 20, 20);
		glDisable(GL_DEPTH_TEST);
		glFlush();
	}
};

class ThreeThreeTwo {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	bool Left = false, Right = false;
	ThreeThreeTwo(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	TPoint P[8]; bool flag[4]; double r[4];
	void Init(void) {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		P[0] = { -1, 1, -1 };  P[1] = { 1, 1, -1 };
		P[2] = { 1, 1, 1 };    P[3] = { -1, 1, 1 };
		P[4] = { -1, -1, -1 }; P[5] = { 1, -1, -1 };
		P[6] = { 1, -1, 1 };   P[7] = { -1, -1, 1 };
	}
	void Reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void Solve(TPoint a, TPoint b, TPoint c, TPoint d, Color C) {
		glColor3d(C.x, C.y, C.z);
		glBegin(GL_POLYGON);
		glVertex3d(a.x, a.y, a.z); glVertex3d(b.x, b.y, b.z);
		glVertex3d(c.x, c.y, c.z); glVertex3d(d.x, d.y, d.z);
		glEnd();
	}
	void Display(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glTranslatef(Move_x, Move_y, Move_z);
		glRotated(r[1], 1.0f, 0.0f, 0.0f);
		glRotated(r[2], 0.0f, 1.0f, 0.0f);
		glRotated(r[3], 0.0f, 0.0f, 1.0f);
		Solve(P[0], P[1], P[2], P[3], Color(1, 0, 0));
		Solve(P[4], P[5], P[6], P[7], Color(0, 1, 0));
		Solve(P[0], P[1], P[5], P[4], Color(0, 0, 1));
		Solve(P[0], P[3], P[7], P[4], Color(1, 1, 0));
		Solve(P[1], P[2], P[6], P[5], Color(1, 0, 1));
		Solve(P[2], P[3], P[7], P[6], Color(0, 1, 1));
		glFlush();
		glDisable(GL_DEPTH_TEST);
	}
};

class Line {
public:
	Point A, B; int Color;
	Line(Point A, Point B, int Color = 0) : A(A), B(B), Color(Color) {}
};

class FourOne {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	bool Cut = false;
	FourOne(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	#define LEFT 1
	#define RIGHT 2
	#define BOTTOM 4
	#define TOP 8
	int C = 3;
	double x1 = -0.9;
	double y1 = 0.8;
	double x2 = 0.8;
	double y2 = -0.8;
	void Init() {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}
	void Recover() {
		//glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POLYGON);
		glColor3d(1, 0, 0);
		glVertex2d(0.5 + Move_x, 0.5 + Move_y); glVertex2d(0.5 + Move_x, -0.5 + Move_y);
		glVertex2d(-0.5 + Move_x, -0.5 + Move_y); glVertex2d(-0.5 + Move_x, 0.5 + Move_y);
		glEnd();

		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(C & 4, C & 2, C & 1);
		Line L = Line(Point(x1, y1), Point(x2, y2), C);
		glVertex2d(x1 + Move_x, y1 + Move_y); glVertex2d(x2 + Move_x, y2 + Move_y);
		glEnd();
		glFlush();
	}
	int encode(double x, double y, double XL, double YB,
		double XR, double YT) { // 求解(x, y)的区域码
		int c = 0;
		if (x < XL) c = c | LEFT;
		else if (x > XR) c = c | RIGHT;
		if (y < YB) c = c | BOTTOM;
		else if (y > YT) c = c | TOP;
		return c;
	}
	void Delete(Line L) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(0, 0, 0);
		glVertex2d(L.A.x + Move_x, L.A.y + Move_y);
		glVertex2d(L.B.x + Move_x, L.B.y + Move_y);
		glEnd();
		glFlush();
	}
	void Insert(Line L) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(L.Color & 4, L.Color & 2, L.Color & 1);
		glVertex2d(L.A.x + Move_x, L.A.y + Move_y);
		glVertex2d(L.B.x + Move_x, L.B.y + Move_y);
		glEnd();
		glFlush();
	}
	void Cohen_Sutherland(Line L, Point Min, Point Max) {
		Delete(L); bool flag = false;
		int code1, code2; //区域码
		for (;;) {
			code1 = encode(L.A.x, L.A.y, Min.x, Min.y, Max.x, Max.y);
			code2 = encode(L.B.x, L.B.y, Min.x, Min.y, Max.x, Max.y);
			if (!(code1 | code2)) { // 可以画线
				flag = true; break;
			}
			if ((code1 & code2) != 0) break;
			if (!code1) { // 起点 在裁剪区 交换
				swap(L.A, L.B);
				swap(code1, code2);
			}
			double k; // 斜率
			if (L.A.x != L.B.x) {
				k = (L.A.y - L.B.y) / (L.A.x - L.B.x);
			}
			if ((LEFT & code1) != 0) {
				L.A.y += (Min.x - L.A.x) * k;
				L.A.x = Min.x;
			}
			else if ((RIGHT & code1) != 0) {
				L.A.y += (Max.x - L.A.x) * k;
				L.A.x = Max.x;
			}
			else if ((BOTTOM & code1) != 0) {
				if (L.A.x != L.B.x) {
					L.A.x += (Min.y - L.A.y) / k;
				}
				L.A.y = Min.y;
			}
			else if ((TOP & code1) != 0) {
				if (L.A.x != L.B.x) {
					L.A.x += (Max.y - L.A.y) / k;
				}
				L.A.y = Max.y;
			}
		}
		if (flag) {
			Insert(L);
		}
	}
};

class FourTwo {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	bool Cut = false;
	FourTwo(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
	int C = 3;
	double x1 = -0.9;
	double y1 = 0.8;
	double x2 = 0.8;
	double y2 = -0.8;

	int C1 = 7;
	double x3 = -0.3;
	double y3 = 0.9;
	double x4 = -0.3;
	double y4 = -0.9;

	int C2 = 5;
	double x5 = -0.9;
	double y5 = -0.1;
	double x6 = 0.9;
	double y6 = -0.1;
	void Init() {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}
	void Recover() {
		//glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glColor3d(1, 0, 0);
		glVertex2d(0.5 + Move_x, 0.5 + Move_y); glVertex2d(0.5 + Move_x, -0.5 + Move_y);
		glVertex2d(-0.5 + Move_x, -0.5 + Move_y); glVertex2d(-0.5 + Move_x, 0.5 + Move_y);
		glEnd();

		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(C & 4, C & 2, C & 1);
		glVertex2d(x1 + Move_x, y1 + Move_y); glVertex2d(x2 + Move_x, y2 + Move_y);
		glEnd();

		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(C1 & 4, C1 & 2, C1 & 1);
		glVertex2d(x3 + Move_x, y3 + Move_y); glVertex2d(x4 + Move_x, y4 + Move_y);
		glEnd();

		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(C2 & 4, C2 & 2, C2 & 1);
		glVertex2d(x5 + Move_x, y5 + Move_y); glVertex2d(x6 + Move_x, y6 + Move_y);
		glEnd();
		glFlush();
	}
	int encode(double x, double y, double XL, double YB,
		double XR, double YT) { // 求解(x, y)的区域码
		int c = 0;
		if (x < XL) c = c | LEFT;
		else if (x > XR) c = c | RIGHT;
		if (y < YB) c = c | BOTTOM;
		else if (y > YT) c = c | TOP;
		return c;
	}
	void Delete(Line L) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(0, 0, 0);
		glVertex2d(L.A.x + Move_x, L.A.y + Move_y);
		glVertex2d(L.B.x + Move_x, L.B.y + Move_y);
		glEnd();
		glFlush();
	}
	void Insert(Line L) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3d(L.Color & 4, L.Color & 2, L.Color & 1);
		glVertex2d(L.A.x + Move_x, L.A.y + Move_y);
		glVertex2d(L.B.x + Move_x, L.B.y + Move_y);
		glEnd();
		glFlush();
	}
	void Cohen_Sutherland(Line L, Point Min, Point Max) {
		Delete(L); bool flag = false;
		int code1, code2; //区域码
		for (;;) {
			code1 = encode(L.A.x, L.A.y, Min.x, Min.y, Max.x, Max.y);
			code2 = encode(L.B.x, L.B.y, Min.x, Min.y, Max.x, Max.y);
			if (!(code1 | code2)) { // 可以画线
				flag = true; break;
			}
			if ((code1 & code2) != 0) break;
			if (!code1) { // 起点 在裁剪区 交换
				swap(L.A, L.B);
				swap(code1, code2);
			}
			double k; // 斜率
			if (L.A.x != L.B.x) {
				k = (L.A.y - L.B.y) / (L.A.x - L.B.x);
			}
			if ((LEFT & code1) != 0) {
				L.A.y += (Min.x - L.A.x) * k;
				L.A.x = Min.x;
			}
			else if ((RIGHT & code1) != 0) {
				L.A.y += (Max.x - L.A.x) * k;
				L.A.x = Max.x;
			}
			else if ((BOTTOM & code1) != 0) {
				if (L.A.x != L.B.x) {
					L.A.x += (Min.y - L.A.y) / k;
				}
				L.A.y = Min.y;
			}
			else if ((TOP & code1) != 0) {
				if (L.A.x != L.B.x) {
					L.A.x += (Max.y - L.A.y) / k;
				}
				L.A.y = Max.y;
			}
		}
		if (flag) {
			Insert(L);
		}
	}
};

class FourThree {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	bool Left = false, Middle = false, Right = false;
	bool NewLine = false;
	int Id = 0; // the number of lines
	FourThree(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}
	vector<Line> G;
	int get(int x, int y) {
		return x + rand() % (y - x + 1);
	}
	void Recover() {
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glColor3d(1, 0, 0);
		glVertex2d(0.5 + Move_x, 0.5 + Move_y); glVertex2d(0.5 + Move_x, -0.5 + Move_y);
		glVertex2d(-0.5 + Move_x, -0.5 + Move_y); glVertex2d(-0.5 + Move_x, 0.5 + Move_y);
		glEnd();
		glFlush();
	}
	void Draw() {
		glLineWidth(1);
		glBegin(GL_LINES);
		int C = get(1, 6);
		glColor3d(C & 4, C & 2, C & 1);
		double x1 = get(0, 10) * (get(0, 1) ? 1 : -1);
		double y1 = get(0, 10) * (get(0, 1) ? 1 : -1);
		double x2 = get(0, 10) * (get(0, 1) ? 1 : -1);
		double y2 = get(0, 10) * (get(0, 1) ? 1 : -1);
		x1 /= 10; y1 /= 10; x2 /= 10; y2 /= 10;
		Line L = Line(Point(x1, y1), Point(x2, y2), C); G.push_back(L);
		glVertex2d(x1 + Move_x, y1 + Move_y); glVertex2d(x2 + Move_x, y2 + Move_y);
		glEnd();
		glFlush();
	}
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
	int encode(double x, double y, double XL, double YB,
		double XR, double YT) { // 求解(x, y)的区域码
		int c = 0;
		if (x < XL) c = c | LEFT;
		else if (x > XR) c = c | RIGHT;
		if (y < YB) c = c | BOTTOM;
		else if (y > YT) c = c | TOP;
		return c;
	}
	void Delete(Line L) {
		glBegin(GL_LINES);
		glColor3d(0, 0, 0);
		glVertex2d(L.A.x + Move_x, L.A.y + Move_y);
		glVertex2d(L.B.x + Move_x, L.B.y + Move_y);
		glEnd();
		glFlush();
	}
	void Insert(Line L) {
		glBegin(GL_LINES);
		glColor3d(L.Color & 4, L.Color & 2, L.Color & 1);
		glVertex2d(L.A.x + Move_x, L.A.y + Move_y);
		glVertex2d(L.B.x + Move_x, L.B.y + Move_y);
		glEnd();
		glFlush();
	}
	void Cohen_Sutherland(Line L, Point Min, Point Max) {
		Delete(L); bool flag = false;
		int code1, code2; //区域码
		for (;;) {
			code1 = encode(L.A.x, L.A.y, Min.x, Min.y, Max.x, Max.y);
			code2 = encode(L.B.x, L.B.y, Min.x, Min.y, Max.x, Max.y);
			if (!(code1 | code2)) { // 可以画线
				flag = true; break;
			}
			if ((code1 & code2) != 0) break;
			if (!code1) { // 起点 在裁剪区 交换
				swap(L.A, L.B);
				swap(code1, code2);
			}
			double k; // 斜率
			if (L.A.x != L.B.x) {
				k = (L.A.y - L.B.y) / (L.A.x - L.B.x);
			}
			if ((LEFT & code1) != 0) {
				L.A.y += (Min.x - L.A.x) * k;
				L.A.x = Min.x;
			}
			else if ((RIGHT & code1) != 0) {
				L.A.y += (Max.x - L.A.x) * k;
				L.A.x = Max.x;
			}
			else if ((BOTTOM & code1) != 0) {
				if (L.A.x != L.B.x) {
					L.A.x += (Min.y - L.A.y) / k;
				}
				L.A.y = Min.y;
			}
			else if ((TOP & code1) != 0) {
				if (L.A.x != L.B.x) {
					L.A.x += (Max.y - L.A.y) / k;
				}
				L.A.y = Max.y;
			}
		}
		if (flag) {
			Insert(L);
		}
	}
};

class FiveOne {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	FiveOne(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		//glShadeModel(GL_SMOOTH);
	}
	void Reshape(int w, int h) {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	}
	vector<Point> Pt;
	bool flag = false; // 是否开始新的画线
	double C(int n, int m) { //计算多项式的系数C(nn,k)
		double sum = 1;
		for(int i = 1; i <= n; i++) {
			sum *= i;
		}
		for(int i = 1; i <= m; i++) {
			sum /= i;
		}
		for(int i = 1; i <= n - m; i++) {
			sum /= i;
		}
		return sum;
	}
	void Work(int n, double t) { // 计算Bezier曲线上点的坐标
		double x = 0, y = 0, Ber;
		for(int k = 0; k < n; k++) {
			Ber = C(n - 1, k) * pow(t, k) * pow(1 - t, n - 1 - k);
			x += Pt[k].x * Ber;
			y += Pt[k].y * Ber;
		}
		glVertex2d(x + Move_x, y + Move_y);
	}
	void Bezier(int n, int m) { //根据控制点，求曲线上的m个点
		for(int i = 0; i <= m; i++) {
			Work(n, i * 1.0 / m);
		}
	}
	void Display() {
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(2); glColor3d(1, 0, 0);
		for (int i = 0; i < (int)Pt.size(); i++) {
			glBegin(GL_POINTS);
			glVertex2d(Pt[i].x + Move_x, Pt[i].y + Move_y);
			glEnd();
		}
		if(flag) {
			glLineWidth(1);
			glBegin(GL_LINE_STRIP); 
			glColor3d(1, 1, 1);
			for(int i = 0; i < (int)Pt.size(); i++) {
				glVertex2d(Pt[i].x + Move_x, Pt[i].y + Move_y);
			}
			glEnd();

			glLineWidth(1);
			glBegin(GL_LINE_STRIP); 
			glColor3d(1, 1, 1);
			Bezier((int)Pt.size(), 1000);
			glEnd();
		}
		glFlush();
	}
};

class FiveTwo {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	FiveTwo(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		//glShadeModel(GL_SMOOTH);
	}
	void Reshape(int w, int h) {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	}
	vector<Point> Pt;
	bool flag = false; // 是否开始新的画线
	double C(int n, int m) { //计算多项式的系数C(nn,k)
		double sum = 1;
		for (int i = 1; i <= n; i++) {
			sum *= i;
		}
		for (int i = 1; i <= m; i++) {
			sum /= i;
		}
		for (int i = 1; i <= n - m; i++) {
			sum /= i;
		}
		return sum;
	}
	void Work(int n, double t) { // 计算Bezier曲线上点的坐标
		double x = 0, y = 0, Ber;
		for (int k = 0; k < n; k++) {
			Ber = C(n - 1, k) * pow(t, k) * pow(1 - t, n - 1 - k);
			x += Pt[k].x * Ber;
			y += Pt[k].y * Ber;
		}
		glVertex2d(x + Move_x, y + Move_y);
	}
	void Bezier(int n, int m) { //根据控制点，求曲线上的m个点
		for (int i = 0; i <= m; i++) {
			Work(n, i * 1.0 / m);
		}
	}
	void Display() {
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(6); glColor3d(1, 0, 0);
		for (int i = 0; i < (int)Pt.size(); i++) {
			glBegin(GL_POINTS);
			glVertex2d(Pt[i].x + Move_x, Pt[i].y + Move_y);
			glEnd();
		}
		if (flag) {
			glLineWidth(1);
			glBegin(GL_LINE_STRIP); 
			glColor3d(1, 1, 1);
			for (int i = 0; i < (int)Pt.size(); i++) {
				glVertex2d(Pt[i].x + Move_x, Pt[i].y + Move_y);
			}
			glEnd();

			glLineWidth(1);
			glBegin(GL_LINE_STRIP); 
			glColor3d(1, 1, 1);
			Bezier((int)Pt.size(), 1000);
			glEnd();
		}
		glFlush();
	}
};

class FiveThreeOne {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	FiveThreeOne(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		//glShadeModel(GL_SMOOTH);
	}
	void Reshape(int w, int h) {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
		glMatrixMode(GL_MODELVIEW);
	}
	/*void processHits(GLint hits, GLuint buffer[]) {
		for (int i = 0; i < hits; i++) {
			ID = buffer[3 + i * 4];
		}
	}*/
	int ID = -1;
	vector<Point> Pt;
	bool flag = true; // 是否开始新的画线
	bool Start = false; // 修改形式模式是否开启
	bool Change = false; // 是否修改形状
	double C(int n, int m) { //计算多项式的系数C(nn,k)
		double sum = 1;
		for (int i = 1; i <= n; i++) {
			sum *= i;
		}
		for (int i = 1; i <= m; i++) {
			sum /= i;
		}
		for (int i = 1; i <= n - m; i++) {
			sum /= i;
		}
		return sum;
	}
	void Work(int n, double t) { // 计算Bezier曲线上点的坐标
		double x = 0, y = 0, Ber;
		for (int k = 0; k < n; k++) {
			Ber = C(n - 1, k) * pow(t, k) * pow(1 - t, n - 1 - k);
			x += Pt[k].x * Ber;
			y += Pt[k].y * Ber;
		}
		glVertex2d(x + Move_x, y + Move_y);
	}
	void Bezier(int n, int m) { //根据控制点，求曲线上的m个点
		for (int i = 0; i <= m; i++) {
			Work(n, i * 1.0 / m);
		}
	}
	void Draw(GLenum mode) {
		glPointSize(6); glColor3d(0, 1, 1);
		for (int i = 0; i < (int)Pt.size(); i++) {
			if (mode == GL_SELECT) glLoadName(i);
			glBegin(GL_POINTS);
			glVertex2d(Pt[i].x + Move_x, Pt[i].y + Move_y);
			glEnd();
		}
		if (flag) {
			glLineWidth(1);
			glBegin(GL_LINE_STRIP); 
			glColor3d(1, 0, 0);
			for (int i = 0; i < (int)Pt.size(); i++) {
				glVertex2d(Pt[i].x + Move_x, Pt[i].y + Move_y);
			}
			glEnd();

			glLineWidth(1);
			glBegin(GL_LINE_STRIP); 
			glColor3d(0, 1, 0);
			Bezier((int)Pt.size(), 1000);
			glEnd();
		}
	}
	void Display() {
		glClear(GL_COLOR_BUFFER_BIT);
		Draw(GL_RENDER);
		glFlush();
	}
};

class FiveThreeTwo {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	FiveThreeTwo(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	bool mouseisdown = false;
	bool loopr = false;
	int mx, my;
	int ry = 30;
	int rx = 30;
	void Init() {
		glClearColor(0, 0, 0, 0);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, cx, cy);
		// 设置投影矩阵(透视投影)  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
		// 设置模型视图矩阵  
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	};   // 改变窗口大小时对视窗进行的操作
	void Display() {
		glClear(GL_COLOR_BUFFER_BIT);
		glTranslatef(Move_x, Move_y, Move_z);
		glRotatef(ry, 0, 1, 0);
		glRotatef(rx, 1, 0, 0);
		glColor3d(1, 0, 1);
		glLineWidth(1);
		glutWireTeapot(0.5);
		glFlush();
	}
};

class SixOne {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	SixOne(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init(void) {
		glClearColor(0, 0, 0, 0);
		//glShadeModel(GL_SMOOTH);
		GLfloat sun_light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
		GLfloat sun_light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		//经过很多次反射后最终遗留在环境中的光线强度（颜色）
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING); //在后面的渲染中使用光照
		glEnable(GL_DEPTH_TEST);

	}
	void Reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, 0, 16, 0, 0, 0, 0, 1, 0);
	}
	void Display(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		GLfloat earth_mat_ambient[] = { 0.5f, 1.0f, 0.5f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 0.5f, 1.0f, 0.5f, 1.0f };
		GLfloat earth_mat_specular[] = { 0.0f, 0.5f, 0.5f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_shininess = 50.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glTranslatef(Move_x, Move_y, Move_z);
		glutSolidSphere(2.5, 40, 32);
		
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		
		glFlush();
	}
};

class SixTwo {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	SixTwo(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	void Init(void) {
		glClearColor(0, 0, 0, 0);
		// glShadeModel(GL_SMOOTH);
		// 设置光照
		GLfloat sun_light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat sun_light_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		//经过很多次反射后最终遗留在环境中的光线强度（颜色）
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING); //在后面的渲染中使用光照
		glEnable(GL_DEPTH_TEST);

	}
	void Reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
	}
	void Work1() {
		GLfloat earth_mat_ambient[] = { 0.7f, 0.0f, 0.5f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 0.7f, 0.0f, 0.5f, 1.0f };
		GLfloat earth_mat_specular[] = { 0.7f, 0.0f, 0.5f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_shininess = 50.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(-25, 25, 0);
		glTranslatef(Move_x, Move_y, Move_z);
		glutSolidSphere(12, 40, 40);
		glPopMatrix();
	}
	void Work2() {
		GLfloat earth_mat_ambient[] = { 0.7f, 0.0f, 0.6f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 0.7f, 0.0f, 0.6f, 1.0f };
		GLfloat earth_mat_specular[] = { 0.7f, 0.0f, 0.6f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_shininess = 50.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(Move_x, Move_y, Move_z);
		glutSolidSphere(12, 40, 40);
		glPopMatrix();
	}
	void Work3() {
		GLfloat earth_mat_ambient[] = { 0.7f, 0.0f, 0.7f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 0.7f, 0.0f, 0.7f, 1.0f };
		GLfloat earth_mat_specular[] = { 0.7f, 0.0f, 0.7f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_shininess = 50.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(25, -25, 0);
		glTranslatef(Move_x, Move_y, Move_z);
		glutSolidSphere(12, 40, 40);
		glPopMatrix();
	}
	void Display(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// 设置材质 球1
		Work1();
		// 设置材质 球2
		Work2();
		// 设置材质 球3
		Work3();
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		
		glFlush();
	}
};

class SixThree {
public:
	bool init;       // the mark variable of Init function
	bool reshape;    // the mark variable of Reshape function
	bool Mouse;      // the mark variable of Mouse function 
	bool Keyboard;   // the mark variable of Keyboard function
	bool Motion;     // the mark variable of Mouse move fuction
	SixThree(bool a = true, bool b = true, bool c = true, bool d = false, bool e = false) : init(a), reshape(b), Mouse(c), Keyboard(d), Motion(e) {}
	bool loopr = true;
	bool mouseisdown = false;
#define stripeImageWidth 32
	GLubyte stripeImage[4 * stripeImageWidth];
	void makeStripeImage(void) { //生成纹理
		for (int j = 0; j < stripeImageWidth; j++) {
			stripeImage[4 * j + 0] = (GLubyte)((j <= 4) ? 255 : 0);
			stripeImage[4 * j + 1] = (GLubyte)((j > 4) ? 255 : 0);
			stripeImage[4 * j + 2] = (GLubyte)0;
			stripeImage[4 * j + 3] = (GLubyte)255;
		}
	}
	// 平面纹理坐标生成
	GLfloat *currentCoeff;
	GLenum currentPlane;
	GLint currentGenMode;
	float roangles = 45.0;
	void Init(void) {
		GLfloat xequalzero[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat slanted[] = { 1.0, 1.0, 1.0, 0.0 };
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST);
		glShadeModel(GL_SMOOTH);
		makeStripeImage();
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage1D(GL_TEXTURE_1D, 0, 4, stripeImageWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		currentCoeff = xequalzero;
		currentGenMode = GL_OBJECT_LINEAR;
		currentPlane = GL_OBJECT_PLANE;
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
		glTexGenfv(GL_S, currentPlane, currentCoeff);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_1D);
		//glShadeModel(GL_SMOOTH);
		// 设置光源
		GLfloat sun_light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
		GLfloat sun_light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		//经过很多次反射后最终遗留在环境中的光线强度（颜色）
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_NORMALIZE);
		glFrontFace(GL_CW);
		// 设置材质
		GLfloat earth_mat_ambient[] = { 0.5f, 1.0f, 0.5f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 0.5f, 1.0f, 0.5f, 1.0f };
		GLfloat earth_mat_specular[] = { 0.0f, 0.5f, 0.5f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_shininess = 50.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

		//roangles = 45.0f;
	}
	void Reshape(int w, int h) {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (w <= h) {
			glOrtho(-3.5, 3.5, -3.5*(GLfloat)h / (GLfloat)w, 3.5*(GLfloat)h / (GLfloat)w, -3.5, 3.5);
		}
		else {
			glOrtho(-3.5*(GLfloat)w / (GLfloat)h, 3.5*(GLfloat)w / (GLfloat)h, -3.5, 3.5, -3.5, 3.5);
		}
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void Display(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(roangles, 0.0, 0.0, 1.0);
		glTranslatef(Move_x, Move_y, Move_z);
		glutSolidSphere(2.0, 32, 32);
		glPopMatrix();
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_1D);
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_AUTO_NORMAL);
		glDisable(GL_NORMALIZE);
		glFlush();
	}
};

class Color_Point {
public:
	double x, y; int R, G, B;
	Color_Point(double x, double y, int a, int b, int c) : x(x), y(y), R(a), G(b), B(c) {}
};

class LINE {
public:
	int R = 255, G = 255, B = 255;
	vector<Color_Point> Line;
	void Display() {
		glColor3d(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		glLineWidth(1);
		glBegin(GL_LINES);
		for (int i = 0; i < (int)Line.size(); i++) {
			glVertex2d(Line[i].x, Line[i].y);
		}
		glEnd();
		glFlush();
	}
};

class TRIANGLE {
public:
	int R = 255, G = 255, B = 255;
	vector<Color_Point> Triangle;
	double Dis(Point a, Point b) {
		return sqrt((a.x - b.x) * (a.x - b.x) * 1.0 + (a.y - b.y) * (a.y - b.y) * 1.0);
	}
	void Work(Point a, Point b) { // 求出另外两个端点的坐标
		glVertex2d(a.x, a.y); 
		Point c; Point d;
		double D = Dis(a, b) / cos(PI / 6) / 2;
		double k;
		if (a.x == b.x && a.y == b.y) {
			c = d = a;
		}
		else if (a.x == b.x) {
			c = b + Point(D, 0);
			d = b + Point(-D, 0);
		}
		else if (a.y == b.y) {
			c = b + Point(0, D);
			d = b + Point(0, -D);
		}
		else {
			k = (a.x - b.x) * 1.0 / (a.y - b.y);
			c = b + Point(D / sqrt(1.0 + k * k), D * k / sqrt(1.0 + k * k));
			d = b + Point(-D / sqrt(1.0 + k * k), -D * k / sqrt(1.0 + k * k));
		}
		glVertex2d(c.x, c.y);
		glVertex2d(d.x, d.y);
	}
	void Display() {
		if ((int)Triangle.size() != 2) return;
		glColor3d(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		Work(Point(Triangle[0].x, Triangle[0].y), Point(Triangle[1].x, Triangle[1].y));
		glEnd();
		glFlush();
	}
};

class RECTANGLE {
public:
	int R = 255, G = 255, B = 255;
	vector<Color_Point> Rectangle;
	void Display() {
		if ((int)Rectangle.size() != 2) return;
		glColor3d(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glVertex2d(Rectangle[0].x, Rectangle[0].y);
		glVertex2d(Rectangle[0].x, Rectangle[1].y);
		glVertex2d(Rectangle[1].x, Rectangle[1].y);
		glVertex2d(Rectangle[1].x, Rectangle[0].y);
		glEnd();
		glFlush();
	}
};

class CYCLE {
public:
	int R = 255, G = 255, B = 255;
	vector<Color_Point> Cycle;
	double Dis(Point a, Point b) {
		return sqrt((a.x - b.x) * (a.x - b.x) * 1.0 + (a.y - b.y) * (a.y - b.y) * 1.0);
	}
	void Display() {
		if ((int)Cycle.size() != 2) return;
		glColor3d(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		double r = Dis(Point(Cycle[0].x, Cycle[0].y), Point(Cycle[1].x, Cycle[1].y));
		glLineWidth(1);
		glBegin(GL_LINE_STRIP);
		glColor3d(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		for (int j = 0; j < 1000; j++) {
			glVertex2d(Cycle[0].x * 1.0 + r * cos(j * PI / 180), Cycle[0].y * 1.0 + r * sin(j * PI / 180));
		}
		glEnd();
		glFlush();
	}
};

class FREELINE {
public:
	int R = 255, G = 255, B = 255;
	vector<Color_Point> FreeLine;
	void Display() {
		glColor3d(R * 1.0 / 255, G * 1.0 / 255, B * 1.0 / 255);
		glLineWidth(1);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < (int)FreeLine.size(); i++) {
			glVertex2d(FreeLine[i].x, FreeLine[i].y);
		}
		glEnd();
		glFlush();
	}
};

class Eraser {
public:
	vector<Point> EraserLine;
	void Display() {
		glLineWidth(6);
		glBegin(GL_LINE_STRIP);
		glColor3d(0, 0, 0);
		for (int i = 0; i < (int)EraserLine.size(); i++) {
			glVertex2d(EraserLine[i].x, EraserLine[i].y);
		}
		glEnd();
		glFlush();
	}
};


extern vector<int> mark_line;
extern vector<int> mark_triangle;
extern vector<int> mark_rectangle;
extern vector<int> mark_cycle;
extern vector<int> mark_freeline;
extern vector<int> mark_eraser;

class Draw {
public:
	int R = 255, G = 255, B = 255;
	double Dis(Point a, Point b) {
		return sqrt((a.x - b.x) * (a.x - b.x) * 1.0 + (a.y - b.y) * (a.y - b.y) * 1.0);
	}
	void Init() {
		glClearColor(0, 0, 0, 1);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Reshape(int cx, int cy) {
		glViewport(0, 0, (GLsizei)cx, (GLsizei)cy);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, (GLdouble)cx, 0.0, (GLdouble)cy);
	};   // 改变窗口大小时对视窗进行的操作
	vector<LINE> Line_Pt;
	void Line_Work(int id) {
		if (mark_line.empty()) {
			return;
		}
		int l, r = mark_line[id]; // 第id段 的区间为[l, r]
		if (id == 0) {
			l = 0;
		}
		else {
			l = mark_line[id - 1];
		}

		for (int i = l; i < r; i++) {
			glColor3d(Line_Pt[i].R * 1.0 / 255, Line_Pt[i].G * 1.0 / 255, Line_Pt[i].B * 1.0 / 255);
			glLineWidth(1);
			glBegin(GL_LINES);
			for (int j = 0; j < (int)Line_Pt[i].Line.size(); j++) {
				glVertex2d(Line_Pt[i].Line[j].x, Line_Pt[i].Line[j].y);
			}
			glEnd();
			glFlush();
		}
		glFlush();
	}
	vector<TRIANGLE> Triangle_Pt;
	void Work(Point a, Point b) { // 求出另外两个端点的坐标
		glVertex2d(a.x, a.y);
		Point c; Point d;
		double D = Dis(a, b) / cos(PI / 6) / 2;
		double k;
		if (a.x == b.x && a.y == b.y) {
			c = d = a;
		}
		else if (a.x == b.x) {
			c = b + Point(D, 0);
			d = b + Point(-D, 0);
		}
		else if (a.y == b.y) {
			c = b + Point(0, D);
			d = b + Point(0, -D);
		}
		else {
			k = (a.x - b.x) * 1.0 / (a.y - b.y);
			c = b + Point(D / sqrt(1.0 + k * k), D * k / sqrt(1.0 + k * k));
			d = b + Point(-D / sqrt(1.0 + k * k), -D * k / sqrt(1.0 + k * k));
		}
		glVertex2d(c.x, c.y);
		glVertex2d(d.x, d.y);
	}
	void Triangle_Work(int id) {
		if (mark_triangle.empty()) {
			return;
		}
		int l, r = mark_triangle[id]; // 第id段 的区间为[l, r]
		if (id == 0) {
			l = 0;
		}
		else {
			l = mark_triangle[id - 1];
		}
		for (int i = l; i < r; i++) {
			glLineWidth(1);
			glBegin(GL_LINE_LOOP);
			glColor3d(Triangle_Pt[i].R * 1.0 / 255, Triangle_Pt[i].G * 1.0 / 255, Triangle_Pt[i].B * 1.0 / 255);
			Work(Point(Triangle_Pt[i].Triangle[0].x, Triangle_Pt[i].Triangle[0].y), 
				Point(Triangle_Pt[i].Triangle[1].x, Triangle_Pt[i].Triangle[1].y));
			glEnd();
		}
		glFlush();
	}
	vector<RECTANGLE> Rectangle_Pt;
	void Rectangle_Work(int id) {
		if (mark_rectangle.empty()) {
			return;
		}
		int l, r = mark_rectangle[id]; // 第id段 的区间为[l, r]
		if (id == 0) {
			l = 0;
		}
		else {
			l = mark_rectangle[id - 1];
		}
		for (int i = l; i < r; i++) {
			glLineWidth(1);
			glBegin(GL_LINE_LOOP);
			glColor3d(Rectangle_Pt[i].R * 1.0 / 255, Rectangle_Pt[i].G * 1.0 / 255, Rectangle_Pt[i].B * 1.0 / 255);
			glVertex2d(Rectangle_Pt[i].Rectangle[0].x, Rectangle_Pt[i].Rectangle[0].y);
			glVertex2d(Rectangle_Pt[i].Rectangle[0].x, Rectangle_Pt[i].Rectangle[1].y);
			glVertex2d(Rectangle_Pt[i].Rectangle[1].x, Rectangle_Pt[i].Rectangle[1].y);
			glVertex2d(Rectangle_Pt[i].Rectangle[1].x, Rectangle_Pt[i].Rectangle[0].y);
			glEnd();
		}
		glFlush();
	}
	vector<CYCLE> Cycle_Pt;
	void Cycle_Work(int id) {
		if (mark_cycle.empty()) {
			return;
		}
		int l, r = mark_cycle[id]; // 第id段 的区间为[l, r]
		if (id == 0) {
			l = 0;
		}
		else {
			l = mark_cycle[id - 1];
		}
		for (int i = l; i < r; i++) {
			double r = Dis(Point(Cycle_Pt[i].Cycle[0].x, Cycle_Pt[i].Cycle[0].y), 
				Point(Cycle_Pt[i].Cycle[1].x, Cycle_Pt[i].Cycle[1].y));
			glLineWidth(1);
			glBegin(GL_LINE_STRIP);
			glColor3d(Cycle_Pt[i].R * 1.0 / 255, Cycle_Pt[i].G * 1.0 / 255, Cycle_Pt[i].B * 1.0 / 255);
			for (int j = 0; j < 1000; j++) {
				glVertex2d(Cycle_Pt[i].Cycle[0].x * 1.0 + r * cos(j * PI / 180), 
					Cycle_Pt[i].Cycle[0].y * 1.0 + r * sin(j * PI / 180));
			}
			glEnd();
		}
		glFlush();
	}
	vector<FREELINE> FreeLine_Pt;
	void FreeLine_Work(int id) {
		if (mark_freeline.empty()) {
			return;
		}
		int l, r = mark_freeline[id]; // 第id段 的区间为[l, r]
		if (id == 0) {
			l = 0; 
		}
		else {
			l = mark_freeline[id - 1];
		}
		for (int j = l; j < r; j++) {
			glLineWidth(1);
			glBegin(GL_LINE_STRIP);
			glColor3d(FreeLine_Pt[j].R * 1.0 / 255, FreeLine_Pt[j].G * 1.0 / 255, FreeLine_Pt[j].B * 1.0 / 255);
			for (int i = 0; i < (int)FreeLine_Pt[j].FreeLine.size(); i++) {
				glVertex2d(FreeLine_Pt[j].FreeLine[i].x, FreeLine_Pt[j].FreeLine[i].y);
			}
			glEnd();
		}
		glFlush();
	}
	vector<Eraser> Eraser_Pt;
	void Eraser_Work(int id) {
		if (mark_eraser.empty()) {
			return;
		}
		int l, r = mark_eraser[id];
		if (id == 0) {
			l = 0;
		}
		else {
			l = mark_eraser[id - 1];
		}
		for (int j = l; j < r; j++) {
			glLineWidth(6);
			glBegin(GL_LINE_STRIP);
			glColor3d(0, 0, 0);
			for (int i = 0; i < (int)Eraser_Pt[j].EraserLine.size(); i++) {
				glVertex2d(Eraser_Pt[j].EraserLine[i].x, Eraser_Pt[j].EraserLine[i].y);
			}
			glEnd();
		}
		glFlush();
	}
};

class REDO{
public:
	int op; int drawoperator; 
	LINE line;
	TRIANGLE triangle;
	RECTANGLE rectangle;
	CYCLE cycle;
	FREELINE freeline;
	Eraser eraser;
	int R, G, B;
	REDO(int a, int b, LINE c, TRIANGLE d, RECTANGLE e, CYCLE f, FREELINE g, Eraser h, int i, int j, int k) : 
		op(a), drawoperator(b), line(c), triangle(d), rectangle(e), cycle(f), 
		freeline(g), eraser(h), R(i), G(j), B(k) {}
};

class REDO_STACK {
public:
	stack<REDO> Stack;
};
