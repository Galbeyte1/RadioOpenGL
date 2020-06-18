// Galbeyte Salad
//    Assignment 1
//    GUI
//    10 June 2020

#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLCDNumber>

#include "globj.h"
int main(int argc, char *argv[])
{
  QApplication app(argc, argv); // needed for all applications

  // Create window and title it
  QWidget *window = new QWidget;
  window->setWindowTitle("Radio");

  GLobj *red_box = new GLobj();

  QLabel *modulation = new QLabel;
  modulation->setText("Modulation");
  QRadioButton *am_radioButton =  new QRadioButton;
  am_radioButton->setText("AM");
  QRadioButton *fm_radioButton =  new QRadioButton;
  fm_radioButton->setText("FM");
  QPushButton *closeButton = new QPushButton;
  closeButton->setText("CLOSE");

  // Create spinbox(output) and slider,dial(input)
  QLabel *bass_label = new QLabel;
  bass_label->setText("Bass");
  QLCDNumber *lcd_bass = new QLCDNumber;
  QSlider *slider_bass = new QSlider(Qt::Vertical);
  slider_bass->setRange(0, 100);

  QLabel *mid_label = new QLabel;
  mid_label->setText("Mid");
  QLCDNumber *lcd_mid = new QLCDNumber;
  QSlider *slider_mid = new QSlider(Qt::Vertical);
  slider_mid->setRange(0, 100);

  QLabel *treble_label = new QLabel;
  treble_label->setText("Treble");
  QLCDNumber *lcd_treble = new QLCDNumber;
  QSlider *slider_treble = new QSlider(Qt::Vertical);
  slider_treble->setRange(0, 100);

  QLabel *volume_label = new QLabel;
  volume_label->setText("Volume");
  QSpinBox *dial_spinBox_volume = new QSpinBox;
  QDial *dial_volume = new QDial;
  dial_spinBox_volume->setRange(0, 100);
  dial_spinBox_volume->setValue(0);
  dial_volume->setRange(0, 100);
  dial_volume->setNotchesVisible(true);

  QLabel *station_label = new QLabel;
  station_label->setText("Station");
  QSpinBox *dial_spinBox_station = new QSpinBox;
  QDial *dial_station = new QDial;
  dial_spinBox_station->setRange(0, 100);
  dial_spinBox_station->setValue(0);
  dial_station->setRange(0, 100);
  dial_station->setNotchesVisible(true);


  // Connect inputs to outputs and vice versa
  //  Sliders and Spinboxes for BASS, MID, TREBLE
  //      Connecting BASS
  QObject::connect(slider_bass, SIGNAL(valueChanged(int)),
  lcd_bass, SLOT(display(int)));
  //      Connecting MID
  QObject::connect(slider_mid, SIGNAL(valueChanged(int)),
  lcd_mid, SLOT(display(int)));
  //      Connecting TREBLE
  QObject::connect(slider_treble, SIGNAL(valueChanged(int)),
  lcd_treble, SLOT(display(int)));
  //  Dials and Spinboxes for Volume and Station
  //    Connecting Volume
  QObject::connect(dial_spinBox_volume, SIGNAL(valueChanged(int)),
  dial_volume, SLOT(setValue(int)));
  QObject::connect(dial_volume, SIGNAL(valueChanged(int)),
  dial_spinBox_volume, SLOT(setValue(int)));
  //    Connecting Station
  QObject::connect(dial_spinBox_station, SIGNAL(valueChanged(int)),
  dial_station, SLOT(setValue(int)));
  QObject::connect(dial_station, SIGNAL(valueChanged(int)),
  dial_station, SLOT(setValue(int)));
  //  CLOSE button
  //    Connecting Close
  QObject::connect(closeButton, SIGNAL(clicked()),
  window, SLOT(close()));

  // Set up (vertical)layout, then add widget to layout
  QVBoxLayout *topleftLayout = new QVBoxLayout;
  topleftLayout->addWidget(modulation);
  topleftLayout->addWidget(am_radioButton);
  topleftLayout->addWidget(fm_radioButton);

  QHBoxLayout *toplayout = new QHBoxLayout;
  toplayout->addLayout(topleftLayout);
  toplayout->addWidget(red_box);
  toplayout->addWidget(closeButton);

  QVBoxLayout *volumeLayout = new QVBoxLayout;
  volumeLayout->addWidget(volume_label);
  volumeLayout->addWidget(dial_volume);
  volumeLayout->addWidget(dial_spinBox_volume);
  QVBoxLayout *stationLayout = new QVBoxLayout;
  stationLayout->addWidget(station_label);
  stationLayout->addWidget(dial_station);
  stationLayout->addWidget(dial_spinBox_station);

  QVBoxLayout *bassLayout = new QVBoxLayout;
  bassLayout->addWidget(lcd_bass);
  bassLayout->addWidget(slider_bass);
  bassLayout->addWidget(bass_label);

  QVBoxLayout *midLayout = new QVBoxLayout;
  midLayout->addWidget(lcd_mid);
  midLayout->addWidget(slider_mid);
  midLayout->addWidget(mid_label);

  QVBoxLayout *trebleLayout = new QVBoxLayout;
  trebleLayout->addWidget(lcd_treble);
  trebleLayout->addWidget(slider_treble);
  trebleLayout->addWidget(treble_label);

  QHBoxLayout *bottomlayout = new QHBoxLayout;
  bottomlayout->addLayout(volumeLayout);
  bottomlayout->addLayout(trebleLayout);
  bottomlayout->addLayout(midLayout);
  bottomlayout->addLayout(bassLayout);
  bottomlayout->addLayout(stationLayout);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(toplayout);
  mainLayout->addLayout(bottomlayout);

  //mainLayout->addWidget(red_box); doesnt work
  // set layout to window

  window->setLayout(mainLayout);
  window->show();

  return app.exec(); // execute app
 }
