// File: BrushApp.cpp - CBrushApp class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushApp.h"
#include "BrushFrame.h"
#include "BrushView.h"
#include "BrushDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CBrushApp object
CBrushApp theApp;

CBrushApp::CBrushApp()
    : CDemoApp(
        RUNTIME_CLASS(CBrushFrame),
        RUNTIME_CLASS(CBrushView),
        RUNTIME_CLASS(CBrushDocument))
{
}

