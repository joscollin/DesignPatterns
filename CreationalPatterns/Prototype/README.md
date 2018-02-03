Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.

The **Prototype pattern** is a creational design pattern used in software development when the type of objects to create is determined by a prototypical instance, which is cloned to produce new objects.

This pattern is used to:
* Avoid subclasses of an object creator in the client application, like the abstract factory pattern does.
* Avoid the inherent cost of creating a new object in the standard way (e.g., using the 'new' keyword) when it is prohibitively expensive for a given application.