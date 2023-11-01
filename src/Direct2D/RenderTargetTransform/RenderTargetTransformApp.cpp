// File: RenderTargetTransformApp.cpp - CRenderTargetTransformApp class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "RenderTargetTransformApp.h"
#include "RenderTargetTransformFrame.h"
#include "RenderTargetTransformView.h"
#include "RenderTargetTransformDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CRenderTargetTransformApp object
CRenderTargetTransformApp theApp;

CRenderTargetTransformApp::CRenderTargetTransformApp()
    : CDemoApp(
        RUNTIME_CLASS(CRenderTargetTransformFrame),
        RUNTIME_CLASS(CRenderTargetTransformView),
        RUNTIME_CLASS(CRenderTargetTransformDocument))
{
}

