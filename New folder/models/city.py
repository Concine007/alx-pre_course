#!/usr/bin/python3
"""Def ine s th e Ci ty cla ss."""
from models.base_model import BaseModel


class City(BaseModel):
    """R epr ese nt a ci ty.

    Attributes:
        state_id (str): Th e st ate i d.
        name (str): Th e na me o f t he ci ty.
    """

    state_id = ""
    name = ""
