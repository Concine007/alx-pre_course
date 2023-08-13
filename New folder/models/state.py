#!/usr/bin/python3
"""Defines th e St at e cl a ss  ."""
from models.base_model import BaseModel


class State(BaseModel):
    """Represent a st at e.

    Attributes:
        name (str): The na me o f t he st at e.
    """

    name = ""
