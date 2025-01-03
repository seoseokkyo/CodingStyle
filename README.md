# 코딩 스타일 견본[Fly me to the Alpha Centauri]

<p align="center">
  <br>
  <img src="./images/common/SolvedTarget_1.jpg">
  <img src="./images/common/SolvedTarget_2.jpg">
  <br>
</p>

목차

1. 프로젝트 개요
2. 코드 설명 및 코드의 로직 작성 이유
3. 느낀점

## 1. 프로젝트 소개

<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/ProgramData.jpg" alt="" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <h3>프로젝트 개요/동기</h3>
      <ul>
        <li>자주 사용하는 코딩 스타일 견본을 위한 깃허브 프로젝트입니다.</li>
        <li>코딩테스트 사이트인 백준의 https://www.acmicpc.net/problem/1011 를 해결하면서 작업한 프로그램을 견본으로 사용했습니다.</li>
      </ul>
    </td>
  </tr>
</table>

## 기술 스택

|	C++	    |   MFC   |
|:------: |:------: |
|![c++]   | ![mfc]  |

<br>

## 2. 코드 설명
우선 해당 문제 풀이를 위한 계산툴 코드에 대한 설명 및 구성한 UI단에서의 코드 설명순으로 진행하겠습니다.

### 2-1. AlphaCentauri-Constructor_Destructor
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/Constructor_Destructor.jpg" alt="Constructor_Destructor" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>컨스트럭터에서 객체의 초기화에 필요한 부분들을 진행</li>
        <li>디스트럭터에서는 해당 객체의 수명주기와 같은 포인터변수등이 있을 경우 할당해제등을 진행</li>
      </ul>
    </td>
  </tr>
</table>

### 2-2. AlphaCentauri-CalcMaxSpeed
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/CalcMaxSpeed.jpg" alt="CalcMaxSpeed" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>엑셀을 활용하여 예시 데이터 및 예상 데이터를 분석하였고 그 결과 최대 속도는 해당 방식으로 구할 수 있을것을 확인</li>
      </ul>
    </td>
  </tr>
</table>

### 2-3. AlphaCentauri-MakeBasicRoute
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/MakeBasicRoute.jpg" alt="MakeBasicRoute" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>기본적으로 최대 속도까지 가속하며 올라가는 구간과 도착지에 최저속도로 감속하여 도달해야 하는 구간의 뼈대가 될 속도가 들어있는 배열 준비를 위한 기능</li>
      </ul>
    </td>
  </tr>
</table>

### 2-4. AlphaCentauri-CountMaxSpeed
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/CountMaxSpeed.jpg" alt="CountMaxSpeed" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>최고 속력을 유지하는 Step의 개수를 구하는 기능</li>
      </ul>
    </td>
  </tr>
</table>

### 2-5. AlphaCentauri-PreProcess
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/PreProcess.jpg" alt="PreProcess" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>이후 계산을 조금 더 편하게 하기위해 전처리를 하는 기능</li>
      </ul>
    </td>
  </tr>
</table>

### 2-6. AlphaCentauri-GetMinWarpCount
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/GetMinWarpCount.jpg" alt="GetMinWarpCount" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>많은 함수 호출 및 이름과 맞지않는 Run 및 Set동작등이 포함되어있지만 기능적으로는 기본적 계산과 그 이후 계산을 위한 뼈대 작성 및 마무리 계산의 전처리, 후처리 기능을 하고있는 함수</li>
        <li>유지보수가 필요한 프로젝트였을 경우 리팩토링을 진행하여야 하는 코드</li>
      </ul>
    </td>
  </tr>
</table>

### 2-7. UI-WireFrameSet
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/UI_WireFrameSet.jpg" alt="UI_WireFrameSet" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>게임업계에서는 해상도가 사용자마다 다르므로 사용할 수 없는 방법이지만 장비등 고정환경에서 아트와 협업을 할 때는 필수적인 좌표 명시형 디자인 방식입니다.</li>
        <li>MFC환경에서는 그냥 임의로 배치하는것보다 익숙하기도 하고 결과물이 임의 배치보다 이쁘게 나오는것 같아 번거롭지만 명시하는 편입니다.</li>
      </ul>
    </td>
  </tr>
</table>

### 2-8. UI-OnBnClickedButtonCalc
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/OnBnClickedButtonCalc1.jpg" alt="OnBnClickedButtonCalc1" style="width: 100%;">
      <img src="./images/common/OnBnClickedButtonCalc2.jpg" alt="OnBnClickedButtonCalc1" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>프로그램에서 Calc버튼을 누르면 동작되는 함수입니다.</li>
        <li>만들어놓은 알파센타우리 툴이 작동하여 필요한 데이터들을 만들고 UI에 표현해주는 기능입니다.</li>
        <li>EXPECTANCY관련기능들은 프로그램 1차 제작 완료 후 추가된 코드들이며 기존 코드로도 같은 결과는 나오지만 속도가 부족하여 테스트케이스를 완수하지 못하는걸 확인 후 기존 코드와 같은 결과를 뽑아내는 공식을 유추해낸 뒤 기존값과 비교를 위해 추가하였습니다.</li>
      </ul>
    </td>
  </tr>
</table>

### 2-9. UI-OnEnUpdateEditEndPos
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/OnEnUpdateEditEndPos.jpg" alt="OnEnUpdateEditEndPos" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>EndPos텍스트에디터의 값이 변경되면 자동으로 실행되는 함수이며 OnBnClickedButtonCalc를 호출합니다.</li>
      </ul>
    </td>
  </tr>
</table>

### 2-10. UI-OnBnClickedButtonDistDown
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/OnBnClickedButtonDistDown.jpg" alt="OnBnClickedButtonDistDown" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>테스트를 원활하게 진행하기 위해 만든 EndPos의 값을 1 감소시키는 버튼입니다.</li>
      </ul>
    </td>
  </tr>
</table>

### 2-11. UI-OnBnClickedButtonDistUp
<table>
  <tr>
    <td style="width: 30%; vertical-align: top;">
      <img src="./images/common/OnBnClickedButtonDistUp.jpg" alt="OnBnClickedButtonDistUp" style="width: 100%;">
    </td>
    <td style="width: 70%; vertical-align: top; text-align: left;">
      <ul>
        <li>테스트를 원활하게 진행하기 위해 만든 EndPos의 값을 1 증가시키는 버튼입니다.</li>
      </ul>
    </td>
  </tr>
</table>

<br>

## 3. 느낀점

이렇게 소소한 프로젝트를 하면서 공부를 하는것도 재미있는 과정이었습니다.

아마 이 문제를 그냥 데이터만 보고 공식만을 뽑아내려 했으면 오히려 이 프로그램을 만들면서 공식까지 도달한 시간보다 훨씬 오래걸렸을 것 같습니다.

또한 그동안 업무를 진행하면서 엑셀로 데이터처리등을 한 게 마냥 헛된일이 아니었구나는 생각을 하게 해주었습니다.

자잘한 리팩토링같은게 필요한 요소들이 보이긴 하지만 이 프로젝트가 간결하게 제가 사용하는 코딩스타일을 보여주기 괜찮아보여서 업로드하게 되었습니다.

<p align="justify">

</p>

<br>

## 라이센스

MIT &copy; [NoHack](mailto:lbjp114@gmail.com)

<!-- Stack Icon Refernces -->

[git]: /images/stack/Git.svg
[github]: /images/stack/GithubDesktop.svg
[ue]: /images/stack/UnrealEngine.svg
[bd]: /images/stack/Blender.svg
[c++]: /images/stack/C++.svg
[mfc]: /images/stack/Microsoft_Foundation_Class.svg
