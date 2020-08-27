#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include <QListWidgetItem>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qtextstream.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void generateStrings(); // Generate random strings method.
    void getCommonSubstring(); // Common substrings search method.

private:
    Ui::MainWindow *ui;
    QStringList inputStringArray; // Input array.
    QStringList commonSubstringArray; // Array of common strings.
    QString searchString;
    QListWidgetItem *selectedItem;
    bool isFirstTime;
    bool searchButtonCanBeActivated;
    QString testString;
    QFile fileName;

private slots:
    void generateClicked();
    void pasteClicked();
    void openFileClicked();
    void enableSearchButton();
    void searchClicked();
    void resultClicked(QListWidgetItem*);
    void aboutClicked();
};

#endif // MAINWINDOW_H
