#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    searchBar = ui->lineEdit;
    suggestionsBox = ui->listWidget;


    loadWordsIntoTrie();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    string prefix = text.toStdString();


    vector<string> suggestions;
    trie.getSuggestions(prefix, suggestions);


    suggestionsBox->clear();
    for (const string& suggestion : suggestions) {
        suggestionsBox->addItem(QString::fromStdString(suggestion));
    }
}




void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    searchBar->setText(item->text());
}



void MainWindow::loadWordsIntoTrie() {
    string filePath = "./words_dictionary.json";
    vector<string> words = JsonParser::parseWordsFromJson(filePath);
    if (words.empty()) {
        qDebug() << "No words loaded from JSON file!";
        return;
    }
    for (const string& word : words) {
        trie.insert(word);
    }
    qDebug() << "Words loaded successfully!";
}

void MainWindow::on_pushButton_2_clicked()
{
    QString inputText = searchBar->text();  // Get input text
    string word = inputText.toStdString();

    // Check if the word exists in the Trie
    if (trie.search(word)) {
        QMessageBox::information(this, "Result", "The spelling is correct!");
    } else {
        QMessageBox::warning(this, "Result", "The spelling is incorrect!");
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString inputText = searchBar->text();  // Get input text
    string word = inputText.toStdString();

    // Get the closest match from the Trie
    vector<string> suggestions;
    trie.getSuggestions(word, suggestions);

    if (!suggestions.empty()) {
        QMessageBox::information(this, "Suggestion",
                                 QString("Did you mean: %1").arg(QString::fromStdString(suggestions[0])));
    } else {
        QMessageBox::warning(this, "No Suggestions", "No suggestions available for the entered word!");
    }
}

