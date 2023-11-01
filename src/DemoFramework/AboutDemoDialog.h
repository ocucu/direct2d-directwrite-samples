// File: AboutDemoDialog.h - CAboutDemoDialog class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

class CAboutDemoDialog final : public CDialog
{
public:
    CAboutDemoDialog(const CString& strCaption);
    virtual ~CAboutDemoDialog() = default;

private:
    // Overridden
    virtual BOOL OnInitDialog() override;
    // Data
    CString m_strCaption;
};
