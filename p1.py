# 프로젝트 문제 1번
# 입력값
input = [10, 40, 30, 60, 30]

def problem1(input):
    # 평균 계산
    mean = sum(input) // len(input)
    
    # 중앙값 계산
    sorted_input = sorted(input)
    median = sorted_input[len(input) // 2]
    
    # 결과 반환
    return [mean, median]

# 함수 실행 및 검증
result = problem1(input)
assert result == [34, 30]
print("정답입니다.")

