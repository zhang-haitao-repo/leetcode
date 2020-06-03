from typing import List
import time
from collections import OrderedDict


class LRUCache:

    def __init__(self, capacity: int):
        self.maxsize = capacity
        self.lrucache = OrderedDict()

    def get(self, key: int) -> int:
        # 说明在缓存中,重新移动字典的尾部
        if key in self.lrucache:
            self.lrucache.move_to_end(key)
        return self.lrucache.get(key, -1)

    def put(self, key: int, value: int) -> None:
        # 如果存在,删掉,重新赋值
        if key in self.lrucache:
            del self.lrucache[key]
        # 在字典尾部添加
        self.lrucache[key] = value
        if len(self.lrucache) > self.maxsize:
            # 弹出字典的头部(因为存储空间不够了)
            self.lrucache.popitem(last=False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

if __name__ == '__main__':
    obj = LRUCache(2)
    obj.put(1, 1)
    obj.put(2, 2)
    print(obj.get(1))
    print(obj.get(2))
    obj.put(3, 3)
    print(obj.get(2))
