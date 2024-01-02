// File: TextLayoutApp.cpp - CTextLayoutApp class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "TextLayoutApp.h"
#include "TextLayoutFrame.h"
#include "TextLayoutView.h"
#include "TextLayoutDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CTextLayoutApp object
CTextLayoutApp theApp;

CTextLayoutApp::CTextLayoutApp()
    : CDemoApp(
        RUNTIME_CLASS(CTextLayoutFrame),
        RUNTIME_CLASS(CTextLayoutView),
        RUNTIME_CLASS(CTextLayoutDocument))
{
}

