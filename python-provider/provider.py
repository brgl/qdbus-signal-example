#!/usr/bin/env python3
# SPDX-License-Identifier: WTFPL

import pydbus
import pydbus_manager
import sys

from gi.repository import GLib
from functools import partial


class Provider:
    """
    <node>
        <interface name='org.foobar.Provider1'>
            <property name='FooBar' type='s' access='read'/>
        </interface>
    </node>
    """

    @property
    def FooBar(self):
        return "foobar foobar"


def add_interface(manager):
    print("Adding object")
    manager.register_object("/org/foobar/Provider1/FooBar", Provider(), None)
    return GLib.SOURCE_REMOVE


if __name__ == "__main__":
    loop = GLib.MainLoop()
    bus = (
        pydbus.SystemBus()
        if len(sys.argv) == 2 and sys.argv[1] == "system"
        else pydbus.SessionBus()
    )
    manager = pydbus_manager.Manager(bus, "org.foobar.Provider1")

    print("Registered the object manager")

    GLib.timeout_add_seconds(5, partial(add_interface, manager))

    print("Scheduled an interface event in 5 seconds")

    loop.run()
