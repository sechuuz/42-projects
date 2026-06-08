from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        super().__init__()
        self._conv_data = []
        self._index = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if len(self._conv_data) == 0:
            raise Exception("No data ingested.")
        dataout = self._conv_data[0]
        self._conv_data.pop(0)
        return dataout


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            for i in data:
                if not isinstance(i, (int, float)):
                    return False
            return True
        return False

    def ingest(self, data: int | float
               | list[int | float]) -> None:
        valid = self.validate(data)
        if not valid:
            raise TypeError("Improper numeric data")
        if isinstance(data, list):
            for i in data:
                self._conv_data.append((self._index, (str(i))))
                self._index += 1
        else:
            self._conv_data.append((self._index, (str(data))))
            self._index += 1


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            for i in data:
                if not isinstance(i, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        valid = self.validate(data)
        if not valid:
            raise TypeError("Improper string data")
        if isinstance(data, list):
            for i in data:
                self._conv_data.append((self._index, i))
                self._index += 1
        else:
            self._conv_data.append((self._index, data))
            self._index += 1


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            for key, val in data.items():
                if not isinstance(key, str) or not isinstance(val, str):
                    return False
            return True
        elif isinstance(data, list):
            for i in data:
                if not isinstance(i, dict):
                    return False
                for key, val in i.items():
                    if not isinstance(key, str) or not isinstance(val, str):
                        return False
            return True
        return False

    def ingest(self, data: dict[str, str]
               | list[dict[str, str]]) -> None:
        valid = self.validate(data)
        if not valid:
            raise TypeError("Improper string data")
        if isinstance(data, list):
            for i in data:
                outlog = f"{i['log_level']}: {i['log_message']}"
                self._conv_data.append((self._index, outlog))
                self._index += 1
        else:
            outlog = f"{data['log_level']}: {data['log_message']}"
            self._conv_data.append((self._index, outlog))
            self._index += 1


def data_processor():
    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Processor...")
    numprc = NumericProcessor()
    print(f" Trying to validate input '42': {numprc.validate(42)}")
    print(f" Trying to validate input 'Hello': {numprc.validate('Hello')}")
    print(" Test invalid ingestion of string 'foo' without prior validation: ")
    try:
        numprc.ingest('foo')
    except TypeError as err:
        print(f" Got exception: {err}")
    print(" Processing data: [1, 2, 3, 4, 5]")
    numprc.ingest([1, 2, 3, 4, 5])
    print(" Extracting 3 values...")
    for i in range(3):
        output = numprc.output()
        print(f" Numeric value {output[0]}: {output[1]}")
    print()
    print("Testing Text Processor...")
    texprc = TextProcessor()
    print(f" Trying to validate input '42': {texprc.validate(42)}")
    print(" Processing data: ['Hello', 'Nexus', 'World']")
    texprc.ingest(['Hello', 'Nexus', 'World'])
    print(" Extracting 1 value...")
    print(f" Text value 0: {texprc.output()[1]}")
    print()
    print("Testing Log Processor...")
    logprc = LogProcessor()
    print(f" Trying to validate input 'Hello': {logprc.validate('Hello')}")
    print(" Processing data: [{'log_level': 'NOTICE', 'log_message': "
          "'Connection to server'}, {'log_level': 'ERROR"
          "', 'log_message': 'Unauthorized access!!'}]")
    logprc.ingest([{'log_level': 'NOTICE',
                    'log_message': 'Connection to server'},
                   {'log_level': 'ERROR',
                    'log_message': 'Unauthorized access!!'}])
    print(" Extracting 2 values...")
    for i in range(2):
        outlog = logprc.output()
        print(f" Log entry {outlog[0]}: {outlog[1]}")


if __name__ == "__main__":
    data_processor()
