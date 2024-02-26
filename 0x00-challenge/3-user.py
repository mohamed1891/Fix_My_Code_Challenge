#!/usr/bin/python3
"""
 User Model
"""
import hashlib
import uuid

class User():
    """
    User class:
    - id: public string unique (uuid)
    - password: private string hash using SHA-256
    """

    __password = None

    def __init__(self):
        """
        Initialize a new user:
        - assigned a unique `id`
        """
        self.id = str(uuid.uuid4())

    @property
    def password(self):
        """
        Password getter
        """
        return self.__password

    @password.setter
    def password(self, pwd):
        """
        Password setter:
        - `None` if `pwd` is `None`
        - `None` if `pwd` is not a string
        - Hash `pwd` using SHA-256 before assigning to `__password`
        """
        if pwd is None or not isinstance(pwd, str):
            self.__password = None
        else:
            # Hash the password using SHA-256
            hashed_password = hashlib.sha256(pwd.encode()).hexdigest()
            self.__password = hashed_password

    def is_valid_password(self, pwd):
        """
        Valid password:
        - `False` if `pwd` is `None`
        - `False` if `pwd` is not a string
        - `False` if `__password` is `None`
        - Compare `__password` with the SHA-256 hash of `pwd`
        """
        return pwd is not None and isinstance(pwd, str) and \
               self.__password is not None and \
               hashlib.sha256(pwd.encode()).hexdigest() == self.__password

if __name__ == '__main__':
    print("Test User")

    user_1 = User()
    assert user_1.id is not None, "New User should have an id"

    user_2 = User()
    assert user_1.id != user_2.id, "User.id should be unique"

    u_pwd = "myPassword"
    user_1.password = u_pwd
    assert user_1.password != u_pwd, "User.password should be hashed"

    assert user_2.password is None, "User.password should be None by default"

    user_2.password = None
    assert user_2.password is None, "User.password should be None if set to None"

    user_2.password = 89
    assert user_2.password is None, "User.password should be None if set to an integer"

    assert user_1.is_valid_password(u_pwd), "is_valid_password should return True if it's the right password"
    assert not user_1.is_valid_password("Fakepwd"), "is_valid_password should return False if it's not the right password"
    assert not user_1.is_valid_password(None), "is_valid_password should return False if compared with None"
    assert not user_1.is_valid_password(89), "is_valid_password should return False if compared with an integer"
    assert not user_2.is_valid_password("No pwd"), "is_valid_password should return False if no password set before"
