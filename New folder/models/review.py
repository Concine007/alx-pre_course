#!/usr/bin/python3
"""D ef in es t he Re vi ew cl as s."""
from models.base_model import BaseModel


class Review(BaseModel):
    """Represent a re vi ew.

    Attributes:
        place_id (str): T he  Pl a c e i d.
        user_id (str): T he Us er i d.
        text (str): Th e te xt o f th e re v ie w.
    """

    place_id = ""
    user_id = ""
    text = ""
