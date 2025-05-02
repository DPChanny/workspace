from openai import OpenAI

client = OpenAI(
    api_key=""
)

GD = "guide"
PP = "presense_penalty"
FP = "frequency_penalty"
MD = "model"
TP = "temperature"

inputs = ["우울할 때 어떻게 해야 해?", " 친구가 없어. ", "자신감이 없어서 더 우울한 것 같아."]

prompts = [
    {
        GD : "대화하듯 설명해줘(최대 3줄)",
        MD : "gpt-3.5-turbo",
        PP : 0.0,
        FP : 0.0,
        TP : 0.5
    },
    {
        GD : "너는 정신과 의사야. 환자에게 설명하듯이 대답해줘(최대 3줄)",
        MD : "gpt-3.5-turbo",
        PP : 1.2,
        FP : 1.2,
        TP : 1.0
    },
]

# 사용자 입력 반복
for index, input in enumerate(inputs):
    print("INPUT " + str(index + 1) + "\n" + input)

    for index, prompt in enumerate(prompts):
        messages = []
        messages.append({"role": "system", "content": prompt[GD]})
        messages.append({"role": "user", "content": input})

        response = client.chat.completions.create(
            model=prompt[MD],
            messages=messages,
            temperature=prompt[TP],         # 창의성 수준
            top_p=0.5,                      # 확률 상위 후보 컷
            max_tokens=500,

            # 고급 매개변수 추가 (기본값 기준 설정)
            presence_penalty=prompt[PP],    # 새로운 주제를 유도할지 (기본: 0.0)
            frequency_penalty=prompt[FP],   # 반복 단어 억제 강도 (기본: 0.0)
            logit_bias={},                  # 특정 토큰에 대한 편향 없음 (기본: 빈 딕셔너리)
        )

        gpt_reply = response.choices[0].message.content
        messages.append({"role": "assistant", "content": gpt_reply})
        print("RESPONSE " + str(index + 1) + "\n" + gpt_reply)

    print("")
