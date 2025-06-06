# 프로젝트 문제 2번
input = ")))()"

def problem2(input):
    # 이 곳에 코드를 작성하세요.
    # 입력 힌트
    left_needed = 0
    right_needed = 0

    for char in input:
        if char == '(':
            right_needed += 1
        else:  
            if right_needed > 0:
                right_needed -= 1
            else:
                left_needed += 1

    result = left_needed + right_needed
    return result

result = problem2(input)

assert result == 3
print("정답입니다.")
