#!/usr/bin/env python

# reference:
# http://www.overclock.net/t/342279/tutorial-using-python-glade-to-create-a-simple-gui-application
# http://fabian-affolter.ch/blog/arduino-controlled-by-a-gtk-interface/

import sys
#import pygtk
import gtk
#gtk.require("3.0")
import gtk.glade
import serial

class goodlight_control:

    PORT = '/dev/ttyACM0'
    SPEED = 9600

    def send_command(self, val):

        print 'sending command %s' % val

        connection = serial.Serial( self.PORT, 
                                    self.SPEED,
                                    timeout=0,
                                    stopbits=serial.STOPBITS_TWO
                                    )
        connection.write(val)
        connection.close()


    def __init__(self):
        gladefile = "goodlight.glade"
        self.widgets = gtk.glade.XML(gladefile)
        dic = {"on_power_toggled" : self.on_power_toggled,
        "on_window1_destroy": self.on_window1_destroy
        }
        self.widgets.signal_autoconnect(dic)

        self.widgets.get_widget("window1").show()
        #self.window.show()

        #filename = "goodlight.glade"
        #builder = gtk.Builder()
        #builder.add_from_file(filename)
        #builder.connect_signals(self)

        #self.wTree = gtk.glade.XML("goodlightcontrol.glade")

        #dic = {
        #    "on_power_activate": self.power,
        #    "on_windowMain_destroy": self.quit
        #    }

        #self.wTree.signal_autoconnect(dic)
        #gt.main()

    def on_power_toggled(self, widget):
        #switch_state = self.wTree.get_widget("power").active()
        #print "power clicked"
        #print widget.get_active()

        power_button_on = widget.get_active()
        command = 0

        if power_button_on:
            command = 1

        if not power_button_on:
            command = 0

        self.send_command(command)


    def on_window1_destroy(self, widget):
        sys.exit(0)

start_gl = goodlight_control()
gtk.main()
