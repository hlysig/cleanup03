import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(
    os.path.realpath(__file__)), "../../../build/src/wrapper/"))

import wrapper

class OC:
    def __init__(self):
        self.hub = None

    def get_hub(self):
        if self.hub == None:
            self.hub = wrapper.Hub.getHub()
        return self.hub
