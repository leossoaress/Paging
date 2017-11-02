# Paging

Paging is a memory management scheme by wich a computer storees and retrieves data from secondary storage. This code had three algorithms of paging: FIFO ( First in First out ), OTM and LRU ( Last Recently Used).

## Introduction

* **FIFO** When a page replacement is needed, the oldest(first) page in the table will be replaced by the refered page.
* **OTM** A theorical algorithms, repleases the page that will not be accessed for the longest time. It is not practicable because there is no way to know when a page will be refered.
* **LRU** The page with the oldest access(reference) on the page table will be repleaced.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them

```
G++ or compatible installed.
```

### Running

To run the code in LINUX, in the directoy file:

```
make
```

And next:

```
./Build/Paging
```

## Built With

* [Atom](https://atom.io/) - Used for code editting.

## Authors

* **Leoberto Soares** - [leossoaress](https://github.com/leossoaress)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
