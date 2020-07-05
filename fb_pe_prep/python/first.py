from csv import QUOTE_MINIMAL, register_dialect, reader

class Dialect:
    """Describe a CSV dialect.
    This must be subclassed (see csv.excel).  Valid attributes are:
    delimiter, quotechar, escapechar, doublequote, skipinitialspace,
    lineterminator, quoting.
    """
    _name = ""
    _valid = False
    # placeholders
    delimiter = None
    quotechar = None
    escapechar = None
    doublequote = None
    skipinitialspace = None
    lineterminator = None
    quoting = None

    def __init__(self):
        if self.__class__ != Dialect:
            self._valid = True
        self._validate()

    def _validate(self):
        try:
            _Dialect(self)
        except TypeError as e:
            # We do this for compatibility with py2.3
            raise Error(str(e))

class exce(Dialect):
    """Describe the usual properties of Excel-generated CSV files."""
    delimiter = ','
    quotechar = '"'
    doublequote = True
    skipinitialspace = True
    lineterminator = '\r\n'
    quoting = QUOTE_MINIMAL
register_dialect("exce", exce)

with open("first.csv", newline = '') as file:
    sr = reader(file, delimiter = ',', dialect="exce",  quotechar = '|')
    for r in sr:
        print ("%%%%".join(r))
