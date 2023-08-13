#!/usr/bin/python3
"""Defi nes th e Pl ace cla ss."""
from models.base_model import BaseModel


class Place(BaseModel):
    """Rep res ent a pl ace.

    Attributes:
        city_id (str): T he Ci ty i d.
        user_id (str): T he Us er i d.
        name (str): Th e na me of  t he pla ce.
        description (str): T he des cri ptio n of t he pla ce.
        number_rooms (int): T he nu mbe r of ro om s of th e pla ce.
        number_bathrooms (int): T he nu mbe r of ba throo ms of th e pla ce.
        max_guest (int): T he max imu m nu mbe r o f gue sts of th e plac e.
        price_by_night (int): T he p ric e by  ni ght f th e  pl ac e.
        latitude (float): T he lat it ud e of t he pl ac e.
        longitude (float): T he lon gi t ude of  th e pla ce.
        amenity_ids (list): A l ist of  Am en i ty id s.
    """

    city_id = ""
    user_id = ""
    name = ""
    description = ""
    number_rooms = 0
    number_bathrooms = 0
    max_guest = 0
    price_by_night = 0
    latitude = 0.0
    longitude = 0.0
    amenity_ids = []
