#include "qtdialog.h"
#include <cassert>
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_point_data.h"
#include "simulation.h"
#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtDialog),
  m_curve{new QwtPlotCurve("Population density")},
  m_plot{new QwtPlot(this)}
{
  ui->setupUi(this);
  assert(this->layout());
  this->layout()->addWidget(m_plot);
  m_plot->setCanvasBackground(QColor(255,255,255));
  m_curve->attach(m_plot);
  m_curve->setStyle(QwtPlotCurve::Lines);
  m_curve->setPen(QPen(QColor(0,0,0)));
  on_start_clicked();
}

QtDialog::~QtDialog()
{
  delete ui;
}

void QtDialog::on_start_clicked()
{

  const double carrying_capacity{ui->parameters->item(0,0)->text().toDouble()};
  const double igr{ui->parameters->item(1,0)->text().toDouble()};
  const double ipd{ui->parameters->item(2,0)->text().toDouble()};
  const int n_generations{ui->parameters->item(3,0)->text().toInt()};

  simulation s(carrying_capacity, igr, ipd, n_generations);
  s.run();

  //Create time series
  std::vector<double> timeseries;
  for (int i=0; i!=n_generations; ++i)
  {
    timeseries.push_back(static_cast<double>(i));
  }

  //Plot
  const auto& outputs = s.get_population_densities();
  m_curve->setData(new QwtPointArrayData(&timeseries[0],&outputs[0],outputs.size()));
  m_plot->replot();
}
