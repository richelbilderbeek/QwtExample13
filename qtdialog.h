#ifndef QTDIALOG_H
#define QTDIALOG_H

#include <QDialog>

struct QwtPlot;
struct QwtPlotCurve;

namespace Ui {
  class QtDialog;
}

class QtDialog : public QDialog
{
  Q_OBJECT //!OCLINT
  
public:
  explicit QtDialog(QWidget *parent = 0);
  QtDialog(const QtDialog&) = delete;
  QtDialog& operator=(const QtDialog&) = delete;
  ~QtDialog();
  
private slots:
  void on_start_clicked();

private:
  Ui::QtDialog *ui;
  QwtPlotCurve * const m_curve;
  QwtPlot * const m_plot;
};

#endif // QTDIALOG_H
