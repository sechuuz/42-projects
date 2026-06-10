from typing import Any, Protocol
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        super().__init__()
        self._conv_data = []
        self._index = 0
        self._processed = 0

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


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        output = []
        for i in data:
            output.append(i[1])
        print("CSV Output:")
        print(",".join(output))


class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        output = []
        for i in data:
            output.append(f'"item_{i[0]}": "{i[1]}"')
        print("JSON Output:")
        print(f'{{{", ".join(output)}}}')


class DataStream():
    def __init__(self):
        self._processors = []
        self._processor_stats = []

    def register_processor(self, proc: DataProcessor) -> None:
        if proc not in self._processors:
            self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for item in stream:
            handled = False
            for proc in self._processors:
                if proc.validate(item):
                    proc.ingest(item)
                    handled = True
                    break
            if not handled:
                print("DataStream error - Can't process element in stream: "
                      f"{item}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if len(self._processors) > 0:
            for proc in self._processors:
                print(f"{proc}: total {proc._processed} items processed, "
                      f"remaining {len(proc._conv_data)} on processor")
        else:
            print("No processor found, no data")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        if nb == 0:
            print("0 elements were consumed")
            return
        for proc in self._processors:
            data = []
            for i in range(nb):
                if proc._conv_data:
                    data.append(proc.output())
            plugin.process_output(data)


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def __str__(self):
        return "Numeric Processor"

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
                self._processed += 1
        else:
            self._conv_data.append((self._index, (str(data))))
            self._index += 1
            self._processed += 1


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def __str__(self):
        return "Text Processor"

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
                self._processed += 1
        else:
            self._conv_data.append((self._index, data))
            self._index += 1
            self._processed += 1


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def __str__(self):
        return "Log Processor"

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
                self._processed += 1
        else:
            outlog = f"{data['log_level']}: {data['log_message']}"
            self._conv_data.append((self._index, outlog))
            self._index += 1
            self._processed += 1


def data_pipeline() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print()
    print("Initialize Data Stream...")
    datstr = DataStream()
    datstr.print_processors_stats()
    print()
    print("Registering Processors")
    processors = [
        NumericProcessor(),
        TextProcessor(),
        LogProcessor()
    ]
    for proc in processors:
        datstr.register_processor(proc)
    print()
    batch = [
        'Hello world',
        [3.14, -1, 2.71],
        [
         {'log_level': 'WARNING',
          'log_message': 'Telnet access! Use ssh instead'},
         {'log_level': 'INFO',
          'log_message': 'User wil is connected'}
        ],
        42,
        ['Hi', 'five']
    ]
    print(f"Send first batch of data on stream: {batch}")
    datstr.process_stream(batch)
    print()
    datstr.print_processors_stats()
    print()
    print("Send 3 processed data from each processor to a CSV plugin:")
    datstr.output_pipeline(3, CSVExportPlugin())
    print()
    datstr.print_processors_stats()
    print()
    batch2 = [
        21,
        ['I love AI',
         'LLMs are wonderful',
         'Stay healthy'],
        [
            {'log_level': 'ERROR',
             'log_message': '500 server crash'},
            {'log_level': 'NOTICE',
             'log_message': 'Certificate expires in 10 days'}
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]
    print(f"Send first batch of data on stream: {batch2}")
    datstr.process_stream(batch2)
    print()
    datstr.print_processors_stats()
    print("Send 5 processed data from each processor to a JSON plugin:")
    datstr.output_pipeline(5, JSONExportPlugin())
    print()
    datstr.print_processors_stats()


if __name__ == "__main__":
    data_pipeline()
