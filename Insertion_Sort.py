def shell_sort(a_list):
    sublist_count = len(a_list) // 2


    while sublist_count > 0:
        for start_position in range(sublist_count):
           
            gap_insertion_sort(a_list, start_position, sublist_count)
        
        
        sublist_count = sublist_count // 2


def gap_insertion_sort(a_list, start, gap):
    
    for i in range(start + gap, len(a_list), gap):
        current_value = a_list[i]
        position = i

        
        while position >= gap and a_list[position - gap] > current_value:
            a_list[position] = a_list[position - gap]
            position = position - gap

        
        a_list[position] = current_value
alist = [45, 23, 53, 12, 9, 34, 78]
shell_sort(alist)
print(alist)
