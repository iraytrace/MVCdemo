# MVCdemo
This is a demonstration of the Model-View-Controller pattern.  It uses the Qt Toolkit.  There are 4 significant commit branches:
1. MVC:  a basic MVC program with a TemperatureSensor model
2. Observer: TemperatureSensor uses Observer pattern
3. Signals: TemperatureSensor uses Signal/Slot pattern
4. SetPointAndFurnace: TemperatureSensor, SetPoint, and Furnace models, with GUI elements.  

In the last branch, the slider/spinbox pair represent multiple views of the same data.  The pattern demonstrate the value of keeping 
data and GUI separate.
