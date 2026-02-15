# 코딩 테스트 성능 비교 예시

코딩 테스트에서 **동작은 유사하지만 시간복잡도 차이가 큰 패턴**을 모아둔 예시입니다.

현재 각 스크립트는 이전 버전 대비 데이터 케이스 수를 2배로 늘려서 비교가 더 분명하게 보이도록 설정되어 있습니다.

## 파일 목록

- `membership_lookup.py`
  - `q in list` (O(N)) vs `q in set` (평균 O(1))
- `string_building.py`
  - 문자열 `+=` 반복 (최악 O(N^2)) vs `''.join` (O(N))
- `range_sum_query.py`
  - 구간합 매번 계산 (O(K*N)) vs 누적합(prefix sum) (O(N+K))
- `deduplication.py`
  - 리스트 기반 중복 제거 (O(N^2)) vs set 보조 중복 제거 (평균 O(N))

## 실행 예시

```bash
python3 python/performances/membership_lookup.py
python3 python/performances/string_building.py
python3 python/performances/range_sum_query.py
python3 python/performances/deduplication.py
```

> 실행 시간은 머신 사양과 랜덤 데이터에 따라 달라질 수 있습니다.
