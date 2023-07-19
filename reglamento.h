#ifndef REGLAMENTO_H
#define REGLAMENTO_H

#include <QMainWindow>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir> // Agregamos esta línea para incluir QDir
#include <QStandardPaths> // Agregamos esta línea para incluir QStandardPaths

QT_BEGIN_NAMESPACE
namespace Ui { class REGLAMENTO; }
QT_END_NAMESPACE

class REGLAMENTO : public QMainWindow
{
    Q_OBJECT

public:
    REGLAMENTO(QWidget *parent = nullptr);
    ~REGLAMENTO();

private slots:
    void on_actionREGLAMENTO_triggered();

private:
    Ui::REGLAMENTO *ui;
     const QString ARCHIVO = ":/Oca.pdf";
};
#endif // REGLAMENTO_H
