// File: DemoFramework.h
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Note: include this in demo application's heder

#pragma once

// solution-shared macros
#include "ValidationMacros.h"

// dllexport/dllimport storage class attributes
#ifndef DEMOFRAMEWORK_EXP
#ifdef DEMOFRAMEWORK_DLL
#define DEMOFRAMEWORK_EXP __declspec(dllexport)
#else
#define DEMOFRAMEWORK_EXP __declspec(dllimport)
#endif
#endif

// enum forward declarations (will be defined in application's header).
enum class SampleId : UINT;         // sample/pane identifiers
enum class FigureId : UINT;         // figure identifiers
enum class BitmapId : UINT;         // bitmap identifiers
enum class BrushTypeId : UINT;      // brush type identifiers
enum class UpdateHint : LPARAM;     // view update hints

// STL stuff
#include <list>
#include <array>
#include <memory>

// exported classes header files
#include "DemoView.h"
#include "DemoApp.h"
#include "DemoDocument.h"
#include "SamplePane.h"
#include "DemoFrame.h"
#include "SampleParameters.h"
#include "DemoDraw.h"
#include "ExtendedComboBox.h"
#include "D2DResourceFactory.h"
#include "D2DText.h"
#include "ChangeTextDialog.h"
