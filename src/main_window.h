#ifndef DOOGIE_MAIN_WINDOW_H_
#define DOOGIE_MAIN_WINDOW_H_

#include <QtWidgets>
#include "cef.h"
#include "cef_widget.h"
#include "page_tree_dock.h"

namespace doogie {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(Cef* cef, QWidget* parent = nullptr);
  ~MainWindow();

  QJsonObject DebugDump();

 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void timerEvent(QTimerEvent* event) override;

 private:
  Cef* cef_;
  PageTreeDock* page_tree_dock_;
};

}  // namespace doogie

#endif  // DOOGIE_MAIN_WINDOW_H_
