#!/usr/bin/env python3
# SPDX-License-Identifier: WTFPL

import pydbus

from gi.repository import GLib

def on_interfaces_added(*args):
    print("InterfacesAdded: args: {}".format(args))

if __name__ == "__main__":
    loop = GLib.MainLoop()
    bus = pydbus.SessionBus()
    intf = bus.get("org.foobar.Provider1", "/org/foobar/Provider1")
    intf.InterfacesAdded.connect(on_interfaces_added)

    print("Connected to InterfacesAdded signal")

    loop.run()
