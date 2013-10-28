from Tkinter import *
import serial

class App:
	def __init__(self, master):
		
		self.brightness = 0
		self.color_temperature = 0
		
		self.serial_port = serial.Serial('/dev/tty.usbmodemfa131', 9600)
		
		master.title('Goodlight Settings')
		master.minsize(width=300,height=50)
		
		frame = Frame(master)
		frame.pack()
		
		brightness_group = LabelFrame(frame, text='Brightness', padx=5, pady=5)
		brightness_group.pack(padx=10, pady=10)
		
		color_temp_group = LabelFrame(frame, text='Color Temperature', padx=5, pady=5)
		color_temp_group.pack(padx=10, pady=10)
		
		self.brightness = Scale(brightness_group, from_=0, to=100, length=225, orient=HORIZONTAL, command=self.set_brightness)
		self.brightness.pack()
		
		self.color_temp = Scale(color_temp_group, from_=1000, to=4000, length=225, orient=HORIZONTAL, command=self.set_color_temp)
		self.color_temp.pack()
		
	def set_brightness(self, value):
		self.brightness = value
		print 'brightness: %s' % self.brightness
		self.serial_port.write('%s,%s\n' % (self.brightness, self.color_temperature))
		
	def set_color_temp(self, value):
		self.color_temperature = value
		print 'color temp: %s' % self.color_temperature
		self.serial_port.write('%s,%s\n' % (self.brightness, self.color_temperature))
		
root = Tk()

app = App(root)

root.mainloop()