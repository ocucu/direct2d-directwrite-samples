// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

// include demo framework library header file
#include "DemoFramework.h"
// include project resources header file
#include "Resource.h"

// project-wide enum definitions
// sample identifiers
enum class SampleId
{
    unknown = 0,
    font,
    alignment,
    wordWrapping,
    trimming,
    direction,
    lineSpacing,
    tabStop,
};

// view updat hints
enum class UpdateHint : LPARAM
{
    demoDocumentChanged = 0,
    fontChanged,
    alignmentChanged,
    wordWrappingChanged,
    trimmingChanged,
    directionChanged,
    lineSpacingChanged,
    tabStopChanged,
};

// incremental tab stop method
enum TAB_STOP_METHOD
{
    TAB_STOP_METHOD_DEFAULT,
    TAB_STOP_METHOD_FIXED
};

#endif //PCH_H
