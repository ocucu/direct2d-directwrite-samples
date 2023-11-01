// File: TextFormatApp.cpp - CTextFormatApp class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "TextFormatApp.h"
#include "TextFormatFrame.h"
#include "TextFormatView.h"
#include "TextFormatDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Framework;

// the one and only CTextFormatApp object
CTextFormatApp theApp;

CTextFormatApp::CTextFormatApp()
    : CDemoApp(
        RUNTIME_CLASS(CTextFormatFrame),
        RUNTIME_CLASS(CTextFormatView),
        RUNTIME_CLASS(CTextFormatDocument))
{
}

