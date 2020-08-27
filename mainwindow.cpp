#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
                       QMainWindow(parent),
                       ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionGenerate,     SIGNAL(triggered()),
            this,                   SLOT(generateClicked()));

    connect(ui->actionSearch,		SIGNAL(triggered()),
            this,                   SLOT(searchClicked()));

    connect(ui->textEdit,           SIGNAL(textChanged()), // Activate checkbox when the Generate button pushed.
            this,                   SLOT(enableSearchButton()));

    connect(ui->listWidgetResult,   SIGNAL(itemClicked(QListWidgetItem*)),
            this,                   SLOT(resultClicked(QListWidgetItem*)));

    connect(ui->actionPaste,		SIGNAL(triggered()),
            this,                   SLOT(pasteClicked()));

    connect(ui->actionOpenFile,     SIGNAL(triggered()),
            this,                   SLOT(openFileClicked()));

    connect(ui->actionAbout,     SIGNAL(triggered()),
            this,                   SLOT(aboutClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/***************[METHODS]*****************************************************/

void MainWindow::generateStrings()
{
    inputStringArray.clear();
    static const char alphabet[] = "aaabbc";
    int alphabetLength = sizeof(alphabet) - 1;
    srand(time(0));
    int arraySize = rand() % 200 + 30;
    int stringSize = 1;
    for (int j = 0; j < arraySize; j++)
    {
        stringSize = rand() % 200 + 50;
        QString tmpStr;
        for (int i = 0; i < stringSize; i++)
        {
            tmpStr.append(alphabet[rand() % alphabetLength]);
        }
        inputStringArray.append(tmpStr);
    }
}

void MainWindow::getCommonSubstring()
{
// Compare symbol-by-symbol
// Results to temp-array if more than 1 symbols same
// Delete dublicates in temp-array
// Sort temp-array
// Compare each temp-array member with rest-of-input-array
// If mached then => result (commonSubstringArray)
    if (!(inputStringArray.isEmpty()))
    {
        QString a = inputStringArray.at(0);
        QString b = inputStringArray.at(1);
        const int a_size = a.size();
        const int b_size = b.size();
        const int solution_size = b_size + 1;
        QVector<int> x(solution_size, 0);
        QVector<int> y(solution_size, 0);
        QVector<int> * previous = &x;
        QVector<int> * current = &y;
        QStringList temp; // Temporary result.
        int max_length = 0;
        int result_index = 0;
        for (int i = a_size - 1; i >= 0; i--)
        {
            for (int j = b_size - 1; j >= 0; j--)
            {
                int & current_match = (*current)[j];
                if (a[i] != b[j])
                {
                    current_match = 0;
                }
                else
                {
                    const int length = 1 + (*previous)[j + 1];
                    if (length > 1)
                    {
                        max_length = length;
                        result_index = i;
                        temp.push_back(a.mid(result_index, max_length));
                    }
                    current_match = length;
                }
            }
            std::swap(previous, current);
        }
        temp.removeDuplicates();
        temp.sort();
        commonSubstringArray.clear();
        int gotEnd = 0;
        for (QStringList::iterator its = temp.begin(); its != temp.end(); its++)
        {
            gotEnd = 0;
            QStringList::Iterator itv = inputStringArray.begin();
            while ((itv != inputStringArray.end()) && (itv->contains(*its)))
            {
                itv++;
                if (itv == inputStringArray.end()) gotEnd = 1;
            }
            if ((!(commonSubstringArray.contains(*its))) && (gotEnd == 1)) commonSubstringArray.append(*its);
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("There is nothing to search.");
        msgBox.exec();
    }
}

/***************[SLOTS]*******************************************************/

void MainWindow::generateClicked()
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);

    searchButtonCanBeActivated = true; // Search button activation.
    generateStrings();
    ui->textEdit->clear();
    ui->listWidgetResult->clear();
    isFirstTime = true; // Trigger for correct UNDO.
    QStringList::Iterator it;
    for (it = inputStringArray.begin(); it != inputStringArray.end(); it++)
    {
        ui->textEdit->append(*it);
    }

    QGuiApplication::restoreOverrideCursor();
}

void MainWindow::pasteClicked()
{
    // Validate if strings number > 1

    searchButtonCanBeActivated = true; // Search button activation.
    QClipboard *pcb = QApplication::clipboard();
    // paste strings into inputStringArray
    QString tmpStr = pcb->text();
    inputStringArray.clear();
    inputStringArray = tmpStr.split('\n');
    // paste strings into textEdit field
    ui->textEdit->clear();
    ui->listWidgetResult->clear();
    for (QStringList::Iterator it = inputStringArray.begin(); it != inputStringArray.end(); ++it)
    {
        ui->textEdit->append(*it);
    }
}

void MainWindow::openFileClicked()
{
// Open TEXT file
// Size validate
// remove empty strings
// File => inputStringArray

    QFile inputFile(QFileDialog::getOpenFileName(this, "Open File", "" , "Text Files (*.txt)"));

    QGuiApplication::setOverrideCursor(Qt::WaitCursor);

    inputFile.open(QIODevice::ReadOnly);
    inputStringArray.clear();
    QTextStream textStream(&inputFile);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            inputStringArray.append(line);
    }
    if (0)/*(inputStringArray.isEmpty())*/
    {
       QMessageBox::information(0, "Error opening strings", "There is no strings");
    }
    else
    {
        searchButtonCanBeActivated = true; // Search button activation.
        ui->textEdit->clear();
        ui->listWidgetResult->clear();
        isFirstTime = true; // Trigger for correct UNDO.
        QStringList::Iterator it;
        for (it = inputStringArray.begin(); it != inputStringArray.end(); it++)
        {
            ui->textEdit->append(*it);
        }
    }
    inputFile.close();

    QGuiApplication::restoreOverrideCursor();
}

void MainWindow::enableSearchButton()
{
    if (searchButtonCanBeActivated == 1)
    {
        //ui->searchButton->setEnabled(true);
        //ui->checkBox->setEnabled(true);
    }
}

void MainWindow::searchClicked()
{
    // Clean previous result
    // getCommonStrings from inputStringArray
    // If it empty, show the message
    // (If checkbox checked, show only results of such lenght)
    ui->listWidgetResult->clear();
    getCommonSubstring();
    isFirstTime = true;
    if (commonSubstringArray.isEmpty())
    {
        ui->listWidgetResult->addItem("Nothing found.");
        ui->listWidgetResult->setEnabled(false);
        /*QMessageBox msgBox;
        msgBox.setText("There is no any common substring.");
        msgBox.exec();*/
    }
    else
    {
        ui->listWidgetResult->addItems(commonSubstringArray);
        ui->listWidgetResult->setEnabled(true);
    }
}

void MainWindow::resultClicked(QListWidgetItem *item)
{
    selectedItem = ui->listWidgetResult->currentItem();
    searchString.clear();
    searchString = item->text(); // String by clicked one.
    QTextDocument *document = ui->textEdit->document();
    QTextCursor highlightCursor(document);
    QTextCursor qursor(document);
    if (isFirstTime == false)
    {
        document->undo(); // Reset the previous.
    }

    qursor.beginEditBlock();

    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    colorFormat.setForeground(Qt::red);
    colorFormat.setFontUnderline(true);

    while ((!highlightCursor.isNull()) && (!highlightCursor.atEnd()))
    {
        highlightCursor = document->find(searchString, highlightCursor, QTextDocument::FindCaseSensitively);
        if (!highlightCursor.isNull())
        {
            highlightCursor.movePosition(QTextCursor::NoMove, QTextCursor::KeepAnchor);
            highlightCursor.mergeCharFormat(colorFormat);
            highlightCursor.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor, 1);
        }
    }

    qursor.endEditBlock();

    isFirstTime = false;
}

void MainWindow::aboutClicked()
{
    QMessageBox::about(this, "About the program", "Common substrings search\nMade by Cyril Anisimov in 2016\nJSC R&D \"Rainbow\"");
}
