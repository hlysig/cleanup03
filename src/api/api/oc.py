import sys
sys.path.insert(0, "../../../build/src/wrapper/")

import wrapper

class OC:
    def __init__(self):
        self.hub = None
    
    def get_hub(self):
        if self.hub == None:
            self.hub = wrapper.Hub.getHub()
        return self.hub

