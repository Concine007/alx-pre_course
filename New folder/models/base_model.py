#!/usr/bin/python3
"""De fin es the Ba s e M od e l   c l  a  ss."""
import models
from uuid import uuid4
from datetime import datetime


class BaseModel:
    """Rep r e se n t s the Ba se Mod el of t he HB nB pro je ct."""

    def __init__(self, *args, **kwargs):
        """In iti ali ze a n ew Ba se Mo d el.

        Args:
            *args (any): Un use d.
            **kwargs (dict): Ke y/val ue  pa irs of  att r i bute s.
        """
        tform = "%Y-%m-%dT%H:%M:%S.%f"
        self.id = str(uuid4())
        self.created_at = datetime.today()
        self.updated_at = datetime.today()
        if len(kwargs) != 0:
            for k, v in kwargs.items():
                if k == "created_at" or k == "updated_at":
                    self.__dict__[k] = datetime.strptime(v, tform)
                else:
                    self.__dict__[k] = v
        else:
            models.storage.new(self)

    def save(self):
        """Upd ate   up dat ed _ at with t he cu rrent  dat et ime."""
        self.updated_at = datetime.today()
        models.storage.save()

    def to_dict(self):
        """Return the dict i o n a  ry of the Bas e M o d el inst ance.

        In clu  des the k ey/va lue pair __class__ representing
        th e  c l as  s  na me of th e obj ect.
        """
        rdict = self.__dict__.copy()
        rdict["created_at"] = self.created_at.isoformat()
        rdict["updated_at"] = self.updated_at.isoformat()
        rdict["__class__"] = self.__class__.__name__
        return rdict

    def __str__(self):
        """Return the print/str re p r e se nt a th e Bas eM odel ins tance."""
        clname = self.__class__.__name__
        return "[{}] ({}) {}".format(clname, self.id, self.__dict__)
