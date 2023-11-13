// File: PhotoEffectsApp.cpp - CPhotoEffectsApp class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "PhotoEffectsApp.h"
#include "PhotoEffectsFrame.h"
#include "PhotoEffectsView.h"
#include "PhotoEffectsDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CPhotoEffectsApp object
CPhotoEffectsApp theApp;

CPhotoEffectsApp::CPhotoEffectsApp()
    : CDemoApp(
        RUNTIME_CLASS(CPhotoEffectsFrame),
        RUNTIME_CLASS(CPhotoEffectsView),
        RUNTIME_CLASS(CPhotoEffectsDocument))
{
}

