#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QFile>
#include <QColorDialog>
#include <QFontDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QRegularExpression>
#include <QMimeData>
#include "direction.h"
#include "aboutdialog.h"
#include "finddialog.h"
#include "gotodialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void findCalled(QString& find, bool shouldMatchCase, bool shouldWrapAround, EDirection direction);
    void goToRowCalled(int rowNumber);

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

    void on_actionFind_triggered();

    void on_actionFirst_Row_triggered();
    void on_actionLast_Row_triggered();
    void on_actionExact_Row_triggered();

    void on_actionColor_triggered();
    void on_actionFont_triggered();

    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
    void on_actionSelect_All_triggered();

    void on_actionSelect_None_triggered();

private:
    Ui::MainWindow *ui;

    const QString APP_NAME = "Subtitle Editor";

    const QString SRT = "srt";
    const QString SUB = "sub";
    const QStringList SUPPORTED_FORMATS = (QStringList() << SRT);

    QStandardItemModel m_model;
    bool m_changed;
    QString m_path;

    void init();

    void clearAllInputs();
    void updateSubtitleStart();
    void updateSubtitleEnd();
    void surroundSelectedTextWithElement(const QString& atStart, const QString& atEnd);
    void selectRow(int rowNumber);
    bool isAnyRowSelected();
    bool anySpinBoxHasFocus();
    void clearFocusOnEverySpinBox();

    void newFile();
    void openFile(QString path = QString());
    void saveFile(QString path);
    void saveFileAs();
    void checkSave();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};
#endif // MAINWINDOW_H
