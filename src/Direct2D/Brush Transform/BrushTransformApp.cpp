// File: BrushTransformApp.cpp - CBrushTransformApp class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushTransformApp.h"
#include "BrushTransformFrame.h"
#include "BrushTransformView.h"
#include "BrushTransformDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CBrushTransformApp object
CBrushTransformApp theApp;

CBrushTransformApp::CBrushTransformApp()
    : CDemoApp(
        RUNTIME_CLASS(CBrushTransformFrame),
        RUNTIME_CLASS(CBrushTransformView),
        RUNTIME_CLASS(CBrushTransformDocument))
{
}

