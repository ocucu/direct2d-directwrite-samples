// File: FilterEffectsApp.cpp - CFilterEffectsApp class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "FilterEffectsApp.h"
#include "FilterEffectsFrame.h"
#include "FilterEffectsView.h"
#include "FilterEffectsDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CFilterEffectsApp object
CFilterEffectsApp theApp;

CFilterEffectsApp::CFilterEffectsApp()
    : CDemoApp(
        RUNTIME_CLASS(CFilterEffectsFrame),
        RUNTIME_CLASS(CFilterEffectsView),
        RUNTIME_CLASS(CFilterEffectsDocument))
{
}

