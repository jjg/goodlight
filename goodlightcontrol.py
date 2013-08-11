#!/usr/bin/env python

import sys
#import pygtk
import gtk
#gtk.require("3.0")
import gtk.glade

class goodlight_control:
    wTree = None

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
        print "power clicked"
        print widget

    def on_window1_destroy(self, widget):
        sys.exit(0)

start_gl = goodlight_control()
gtk.main()
