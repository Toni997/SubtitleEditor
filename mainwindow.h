#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QCloseEvent>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTextDocument>
#include <QLabel>
#include <QFont>
#include "aboutdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_txtSubtitleEdit_textChanged();
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionExit_triggered();
    void on_actionBold_triggered();
    void on_actionItalic_triggered();
    void on_actionUnderline_triggered();

    void itemChanged(QStandardItem *item);

    void on_tblSubtitlesView_clicked(const QModelIndex &index);

    void on_actionAbout_triggered();
    void on_actionAdd_Row_triggered();
    void on_actionEdit_Row_triggered();
    void on_actionDelete_Row_triggered();

    void on_sbStartMilliseconds_valueChanged(int arg1);
    void on_sbStartSeconds_valueChanged(int arg1);
    void on_sbStartMinutes_valueChanged(int arg1);
    void on_sbStartHours_valueChanged(int arg1);
    void on_sbEndMilliseconds_valueChanged(int arg1);
    void on_sbEndSeconds_valueChanged(int arg1);
    void on_sbEndMinutes_valueChanged(int arg1);
    void on_sbEndHours_valueChanged(int arg1);
    void on_actionZoom_in_triggered();
    void on_actionZoom_out_triggered();

private:
    Ui::MainWindow *ui;

    const QString APP_NAME = "Subtitle Editor";

    QStandardItemModel m_model;
    bool m_changed;
    QString m_path;

    void init();

    void clearAllInputs();
    void updateSubtitleStart();
    void updateSubtitleEnd();
    void surroundSelectedTextWithElement(const QString& atStart, const QString& atEnd);

    void newFile();
    void openFile();
    void saveFile(QString path);
    void saveFileAs();
    void checkSave();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
