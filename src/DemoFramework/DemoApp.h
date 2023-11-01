// File: DemoApp.h - CDemoApp class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

class CDemoDocument;
class CSamplePane;
class DEMOFRAMEWORK_EXP CDemoApp : public CWinAppEx
{
protected:
    CDemoApp(
        CRuntimeClass* pFrameClass,
        CRuntimeClass* pViewClass,
        CRuntimeClass* pDocumentClass = NULL);

protected:
    // Overridden
    virtual BOOL InitInstance() override;
    virtual int ExitInstance() override;

    // Data
    CRuntimeClass* m_pFrameClass{ NULL };
    CRuntimeClass* m_pViewClass{ NULL };
    CRuntimeClass* m_pDocumentClass{ NULL };

private:
    // Message handlers
    DECLARE_MESSAGE_MAP()
    afx_msg void OnAppAbout();
};
