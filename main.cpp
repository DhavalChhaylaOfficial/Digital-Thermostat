#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>

// Constants for temperature range
const int MIN_TEMPERATURE = 0;
const int MAX_TEMPERATURE = 100;

class TemperatureSensor {
public:
    int getCurrentTemperature() {
        // Simulate temperature variations by generating random values
        return MIN_TEMPERATURE + rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1);
    }
};

class Thermostat : public QWidget {
    Q_OBJECT

public:
    Thermostat(QWidget *parent = nullptr) : QWidget(parent) {
        // Create labels for current and desired temperatures
        currentTemperatureLabel = new QLabel("Current Temperature: - °C");
        desiredTemperatureLabel = new QLabel("Desired Temperature: - °C");

        // Create a slider for adjusting the desired temperature
        temperatureSlider = new QSlider(Qt::Horizontal);
        temperatureSlider->setRange(MIN_TEMPERATURE, MAX_TEMPERATURE);

        // Create an "Apply" button to apply the desired temperature
        QPushButton *applyButton = new QPushButton("Apply");
        connect(applyButton, &QPushButton::clicked, this, &Thermostat::applyDesiredTemperature);

        // Create a layout and add the labels, slider, and button to it
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(currentTemperatureLabel);
        layout->addWidget(desiredTemperatureLabel);
        layout->addWidget(temperatureSlider);
        layout->addWidget(applyButton);

        // Set the layout for the widget
        setLayout(layout);

        // Connect the slider's valueChanged signal to the setDesiredTemperature slot
        connect(temperatureSlider, &QSlider::valueChanged, this, &Thermostat::setDesiredTemperature);

        // Create a timer to update the temperature readings every second
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Thermostat::updateTemperature);
        timer->start(1000);

        // Initialize the desired temperature to the current slider value
        setDesiredTemperature(temperatureSlider->value());
    }

public slots:
    void setDesiredTemperature(int temperature) {
        // Update the desired temperature and label
        desiredTemperature = temperature;
        desiredTemperatureLabel->setText(QString("Desired Temperature: %1 °C").arg(desiredTemperature));
    }

    void updateTemperature() {
        // Get the current temperature from the temperature sensor
        int currentTemperature = temperatureSensor.getCurrentTemperature();

        // Update the current temperature label
        currentTemperatureLabel->setText(QString("Current Temperature: %1 °C").arg(currentTemperature));

        // Adjust the background color and output a debug message based on the temperature comparison
        if (currentTemperature < desiredTemperature) {
            setStyleSheet("background-color: red;");
            qDebug() << "Heating system: ON";
        } else if (currentTemperature > desiredTemperature) {
            setStyleSheet("background-color: blue;");
            qDebug() << "Cooling system: ON";
        } else {
            setStyleSheet("");
            qDebug() << "Heating/Cooling system: OFF";
        }
    }

    void applyDesiredTemperature() {
        // Apply the desired temperature from the slider
        int temperature = temperatureSlider->value();
        setDesiredTemperature(temperature);
        qDebug() << "Desired temperature applied: " << temperature << "°C";
    }

private:
    TemperatureSensor temperatureSensor; // Instance of the temperature sensor
    QLabel *currentTemperatureLabel; // Label to display the current temperature
    QLabel *desiredTemperatureLabel; // Label to display the desired temperature
    QSlider *temperatureSlider; // Slider to adjust the desired temperature
    int desiredTemperature; // Desired temperature value
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Thermostat thermostat; // Create an instance of the Thermostat widget
    thermostat.show(); // Show the widget

    return app.exec(); // Start the application event loop
}

#include "main.moc"
