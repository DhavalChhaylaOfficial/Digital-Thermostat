# Digital-Thermostat

This project implements a digital thermostat system simulation with a graphical user interface (GUI) using the Qt framework. The simulation allows users to set the desired temperature and observe the current temperature readings. The control algorithm adjusts a virtual heating or cooling system based on the simulated temperature readings and the desired temperature set by the user.

## Architecture

The digital thermostat simulation follows a client-server architecture:

- The client side is responsible for the graphical user interface (GUI) and user interactions. It displays the current temperature, desired temperature, and allows users to adjust the desired temperature using a slider and apply the changes.

- The server side simulates the temperature readings from different sensors and controls the virtual heating or cooling system based on the desired temperature and simulated temperature readings.

- The simulation utilizes the Qt framework's signal and slot mechanism for communication between the client and server components.

## Design Decisions

1. **GUI Selection**: The simulation utilizes the Qt Widgets module to create a simple and intuitive GUI. It includes labels for displaying temperature information, a slider for adjusting the desired temperature, and an "Apply" button to apply the desired temperature.

2. **Temperature Simulation**: The temperature simulation is implemented in the `TemperatureSensor` class. It generates random temperature values within a specified range to simulate temperature variations. The simulation can be further extended to incorporate more sophisticated algorithms based on specific patterns or factors.

3. **Control Logic**: The control logic for adjusting the virtual heating or cooling system is implemented in the `Thermostat` class. It compares the current temperature readings with the desired temperature and provides visual feedback to indicate the heating or cooling system's state.

4. **Modularity and Reusability**: The code is organized into separate classes to enhance modularity and reusability. The `TemperatureSensor` class encapsulates the temperature simulation, while the `Thermostat` class handles the GUI and control logic. This modular design allows for easy modification or extension of the system.

## Building and Running the Simulation

To build and run the digital thermostat simulation, follow these steps:

1. Ensure you have the Qt framework installed on your system. The code is compatible with Qt 5 or later versions.

2. Open a terminal or command prompt and navigate to the directory containing the source code files.

3. Run the following commands to build the simulation:
    - qmake
    - make
  
This will generate the executable for the simulation.

4. Run the simulation by executing the generated binary file.

The GUI window will appear, allowing you to set the desired temperature and observe the current temperature readings.

5. Adjust the desired temperature using the slider. Click the "Apply" button to apply the changes.

6. The simulation will update the current temperature readings and provide visual feedback based on the desired temperature and simulated temperature readings.

7. Close the simulation window to exit the program.

## Conclusion

The digital thermostat simulation provides a graphical interface for setting the desired temperature and monitoring the current temperature readings. It demonstrates the control logic for adjusting a virtual heating or cooling system based on user input and simulated temperature values. The modular design and use of the Qt framework facilitate code reusability and maintainability.

Feel free to explore and modify the code to meet your specific requirements or to extend the functionality further.






