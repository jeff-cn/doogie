#include "cef_widget.h"
#include <Windows.h>

void CefWidget::InitBrowser(const QString &url) {
  CefBrowserSettings settings;
  browser_ = CefBrowserHost::CreateBrowserSync(window_info_,
                                               handler_,
                                               CefString(url.toStdString()),
                                               settings,
                                               nullptr);
}

void CefWidget::UpdateSize() {
  // Basically just set the browser handle to the same dimensions as widget
  if (browser_) {
    auto browser_host = browser_->GetHost();
    auto browser_win = browser_host->GetWindowHandle();
    SetWindowPos(browser_win, (HWND) this->winId(), 0, 0,
                 this->width(), this->height(),
                 SWP_NOZORDER);
    browser_host->NotifyMoveOrResizeStarted();
  }
}