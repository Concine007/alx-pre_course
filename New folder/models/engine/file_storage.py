#!/usr/bin/python3
"""De fi ne s t he  File S t o r a ge  cl a s s."""
import json
from models.base_model import BaseModel
from models.user import User
from models.state import State
from models.city import City
from models.place import Place
from models.amenity import Amenity
from models.review import Review


class FileStorage:
    """R e p r es en t an  ab  st ra cted  storage engine.

    Attributes:
        __file_path (str): Th e n ame of th e fi le to s ave  ob ject s to.
        __objects (dict): A dic ti on ar y of ins ta ntia ted ob ject s.
    """
    __file_path = "file.json"
    __objects = {}

    def all(self):
        """Re tu rn th e dictionary __objects."""
        return FileStorage.__objects

    def new(self, obj):
        """S et i n __ob je c t s obj  with k ey <obj_class_name>.id"""
        ocname = obj.__class__.__name__
        FileStorage.__objects["{}.{}".format(ocname, obj.id)] = obj

    def save(self):
        """Serialize __objects t o th e JS ON  f ile  __file_path."""
        odict = FileStorage.__objects
        objdict = {obj: odict[obj].to_dict() for obj in odict.keys()}
        with open(FileStorage.__file_path, "w") as f:
            json.dump(objdict, f)

    def reload(self):
        """De seri aliz e the  J SON  file __file_ pa t h  to __objects ,exi s t s."""
        try:
            with open(FileStorage.__file_path) as f:
                objdict = json.load(f)
                for o in objdict.values():
                    cls_name = o["__class__"]
                    del o["__class__"]
                    self.new(eval(cls_name)(**o))
        except FileNotFoundError:
            return
