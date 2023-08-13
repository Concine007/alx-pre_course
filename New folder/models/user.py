#!/usr/bin/python3
"""Defines th e Us er cl   ass."""
from models.base_model import BaseModel


class User(BaseModel):
    """Represent a Us er.

    Attributes:
        email (str): Th e ema il of  th e us er.
        password (str): The pa s s w o rd of th e us er.
        first_name (str): Th  e fi rs t  na m e of th e us er.
        last_name (str): T he las t  na me  of  th e us er.
    """

    email = ""
    password = ""
    first_name = ""
    last_name = ""
