#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include "imagefunctions.h"
bool MainWindow::use=1;
bool MainWindow::pos_1=0;
bool MainWindow::pos_2=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image_work=ImageFunctions::do_nothing;
    load_image();
    make_inner_widgets();

}

void MainWindow::load_image()//
{
    /* Загрузка изображения, с которым будет вся работа.
     *  Должно вызываться до всех остальных функций.
    */

    // нужно корректно склеить путь до файла, чтобы слеши были правильные
    QDir dir;
    // Сейчас путь dir == QApplication::applicationDirPath()
    QString path = dir.absoluteFilePath("image/cat.jpg");

    if (!image.load(path))
    {
        QString err_msg = QString("Не смог загрузить картинку<br>Искал по пути: %1").arg(path);
        qDebug() << err_msg.split("<br>");
        QMessageBox::critical(this
                              , "Ошибка"
                              , err_msg);
        exit(-1);
    }
    image = image
                .scaled(800, 600, Qt::KeepAspectRatio)
                .convertToFormat(QImage::Format_RGBA8888_Premultiplied);
    image_filter=image;
}

void MainWindow::make_inner_widgets()
{
    qlayout = new QHBoxLayout();
    this->centralWidget()->setLayout(qlayout);
    this->setMinimumHeight(400);
    this->setMinimumWidth(800 + 256 + 20);


    //ImageFunctions::Histogram::setHistogramData(image, histogramData);
    img_widget = new ImageWidget(this);
    img_widget->set_image(image);

    qlayout->addWidget(img_widget);
    qlayout->addWidget(img_widget->get_histogram());
}

bool MainWindow::make_and_save_image()
{

    QPainter painter;
    QImage img_tmp = QImage(800, 600, QImage::Format_RGBA8888_Premultiplied);

    painter.begin(&img_tmp);
    painter.setBrush(Qt::red);
    painter.drawRect(0,0,300, 300);
    painter.setBrush(Qt::blue);
    painter.drawRect(300, 300, 200, 100);
    painter.end();

    QString path = QString("{}\\picture.png").arg(QApplication::applicationDirPath());
    if(!img_tmp.save(path))
    {
        qDebug() << "Не смог сохранить картинку: "<< path;
        return false;
    }
    qDebug() << "Сделал и сохранил картинку: "<< path;
    return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_autor_triggered()
{

}

void MainWindow::on_about_triggered()
{

}

void MainWindow::on_blackwhite_triggered()
{
    MainWindow::pos_1=0;
    MainWindow::pos_2=0;
    image_work=ImageFunctions::Image::black_and_white;
     image_filter=image;
      setToBrightnessMap(this->image_filter);
     this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_inversion_triggered()
{
    MainWindow::pos_1=0;
    MainWindow::pos_2=0;
    image_work=ImageFunctions::Image::inversion;
    image_filter=image;
     setToBrightnessMap(this->image_filter);

    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_porog_triggered()
{
    MainWindow::pos_1=1;
    MainWindow::pos_2=0;
     image_work=ImageFunctions::Brightness::doterstep;
     image_filter=image;
    setToBrightnessMap(this->image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_logorifm_triggered()
{
    MainWindow::pos_1=1;
    MainWindow::pos_2=0;
    image_work=ImageFunctions::Brightness::logarithmic;
     image_filter=image;
      setToBrightnessMap(this->image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_piecewise_linear_triggered()
{
    MainWindow::pos_1=1;
    MainWindow::pos_2=1;
    image_work=ImageFunctions::Brightness::piecewise_linear;
    image_filter=image;
    setToBrightnessMap(this->image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_power_triggered()
{
    MainWindow::pos_1=1;
    MainWindow::pos_2=1;
    image_work=ImageFunctions::Brightness::power;
    image_filter=image;
     setToBrightnessMap(this->image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_equalization_triggered()
{

}

void MainWindow::on_normal_triggered()
{

}

void MainWindow::on_porog_1_triggered()
{
    MainWindow::pos_1=1;
    MainWindow::pos_2=0;
    image_work=ImageFunctions::Image::doterstep_1;
    image_filter=image;
     setToBrightnessMap(this->image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_porog_2_triggered()
{
    MainWindow::pos_1=1;
    MainWindow::pos_2=0;
    image_work=ImageFunctions::Image::doterstep_2;
    image_filter=image;
     setToBrightnessMap(this->image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_dft_triggered()
{
    image_filter=image;
     ImageFunctions::DFT::fourier(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_averaged_triggered()
{

    image_filter=image;
     ImageFunctions::filters::box(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}
void MainWindow::on_median_triggered()
{
    image_filter=image;
     ImageFunctions::filters::median(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_Gaus_triggered()
{
    image_filter=image;
     ImageFunctions::filters::gaus(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}



void MainWindow::on_Loplassian_triggered()
{
    image_filter=image;
     ImageFunctions::filters::laplasian(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}


void MainWindow::on_Derivatives_x_triggered()
{
     image_filter=image;
     ImageFunctions::filters::derivatives_x(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_Sobel_x_triggered()
{
    image_filter=image;
     ImageFunctions::filters::sobela_x(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_Shahuro_triggered()
{
    image_filter=image;
     ImageFunctions::filters::shahuro(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_Derivatives_y_triggered()
{
    image_filter=image;
     ImageFunctions::filters::derivatives_y(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}

void MainWindow::on_Sobel_y_triggered()
{
    image_filter=image;
     ImageFunctions::filters::sobela_y(image,image_filter);
    this->img_widget->set_image(this->image_filter);
}
