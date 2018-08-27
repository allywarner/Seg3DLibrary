#include <qapplication.h>
#include <qpushbutton.h>
#include "Seg3D_lib.h"
#include <iostream>
#include <QtCore>
#include <QtWidgets>

void showSeg3DWidget()
{
  Seg3DLibrary::importDataFile("C:/Users/Ally/Documents/T2_AW_Corrected.nrrd");
  Seg3DLibrary::importSegFile("C:/Users/Ally/Documents/HeadSegmentation.nrrd");
  Seg3DLibrary::makeSeg3DWidget()->show();
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  auto Context = Seg3DLibrary::Context::makeContext(&app);

  // dummy application code
  QWidget* widget = new QWidget();
  auto mainLayout_ = new QVBoxLayout();
  widget->setLayout(mainLayout_);

  QPushButton* run_button_ = new QPushButton("Launch Seg3D");
  mainLayout_->addWidget(run_button_);

  QObject::connect(run_button_, &QPushButton::clicked, showSeg3DWidget);
  widget->show();
  // end dummy application

  return app.exec();
}
